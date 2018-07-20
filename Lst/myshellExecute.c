void execute(char *args[]) {                    // コマンドを実行する
  if (strcmp(args[0], "cd")==0) {               // cd コマンド（内部コマンド）
    if (args[1]==NULL)                          //   引数があるか調べて
      fprintf(stderr,"cdの引数が不足\n");
    else if (chdir(args[1])<0)                  //   親プロセスが chdir する
      perror(args[1]);
  } else {                                      // 外部コマンドなら
    int pid, status;
    if ((pid = fork()) < 0) {                   //   新しいプロセスを作る
      perror("fork");
      exit(1);
    }
    if (pid==0) {                               //   子プロセスなら
      execvp(args[0], args);                    //     コマンドを実行
      perror(args[0]);
      exit(1);
    }
    while (wait(&status) != pid)                //   親は子の終了を待つ
      ;
  }
}
