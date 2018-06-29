#include <stdio.h>                    // perror のために必要
#include <stdlib.h>                   // exit のために必要
#include <unistd.h>                   // fork, execve のために必要
#include <sys/wait.h>                 // wait のために必要
char *execpath="/bin/date";
int main(int argc, char *argv[], char *envp[]) {
  int pid;
  if ((pid=fork())<0) {               // 分身を作る
    perror(argv[0]);                  // fork がエラーなら
    exit(1);                          // 親プロセスをエラー終了
  }
  if (pid!=0) {                       // pid が 0 以外なら自分は親プロセス
    int status;
    wait(&status);                    //   子プロセスが終了するのを待つ
  } else {                            // pid が 0 なら自分は子プロセス
    execl(execpath, "date", NULL);    //   date プログラムを実行（execlを使用してみた）
    perror(execpath);                 //   exec が戻ってくるならエラー
    exit(1);                          //   エラー時はここで子プロセスを終了
  }
  exit(0);                            // 親プロセスを正常終了
}
