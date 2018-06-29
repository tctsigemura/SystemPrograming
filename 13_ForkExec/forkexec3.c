#include <stdio.h>                    // perror のために必要
#include <stdlib.h>                   // exit のために必要
#include <unistd.h>                   // fork, execve のために必要
#include <sys/wait.h>                 // wait のために必要
extern char **environ;
char *args[] = {"date", NULL};
char *execpath="/bin/date";

int main(int argc, char *argv[], char *envp[]) {
  int pid;
  for (int i=1; argv[i]!=NULL; i++) {
    putenv(argv[i]);                    // 環境変数を変更する
    if ((pid=fork())<0) {               // 分身を作る
      perror(argv[0]);                  // fork がエラーなら
      exit(1);                          // 親プロセスをエラー終了
    }
    if (pid!=0) {                       // pid が 0 以外なら自分は親プロセス
      int status;
      wait(&status);                    //   子プロセスが終了するのを待つ
    } else {                            // pid が 0 なら自分は子プロセス
      execve(execpath, args, environ);  //   date プログラムを実行
      perror(execpath);                 //   exec が戻ってくるならエラー
      exit(1);                          //   エラー時はここで子プロセスを終了
    }
  }
  exit(0);                            // 親プロセスを正常終了
}
/* 実行例
$ forkexec3 LC_TIME=ja_JP.UTF-8 LC_TIME=ru_RU.UTF-8 TZ=Cuba
2016年 7月18日 月曜日 22時25分51秒 JST
понедельник, 18 июля 2016 г. 22:25:51 (JST)
понедельник, 18 июля 2016 г. 09:25:51 (CDT)
*/
