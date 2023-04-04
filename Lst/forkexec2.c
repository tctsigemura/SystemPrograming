#include <stdio.h>                    // perror のために必要
#include <stdlib.h>                   // exit のために必要
#include <unistd.h>                   // fork, execve のために必要
#include <sys/wait.h>                 // wait のために必要
char *execpath="/bin/date";
int main(int argc, char *argv[], char *envp[]) {
  int pid;
  for (int i=1; argv[i]!=NULL; i++) {
    if ((pid=fork())<0) {             // 分身を作る
      perror(argv[0]);                // fork がエラーなら
      exit(1);                        // 親プロセスをエラー終了
    }
    if (pid!=0) {                     // pid が 0 以外なら自分は親プロセス
      int status;
      while (wait(&status)!=pid)      //   子プロセスが終了するのを待つ
        ;
    } else {                          // pid が 0 なら自分は子プロセス
      putenv(argv[i]);                //   環境変数を変更する
      execl(execpath, "date", NULL);  //   date プログラムをロード・実行
      perror(execpath);               //   execl が戻ってくるならエラー
      exit(1);                        //   エラー時はここで子プロセスを終了
    }
  }
  exit(0);                            // 親プロセスを正常終了
}
/* 実行例
% ./forkexec2 LC_TIME=ja_JP.UTF-8 LC_TIME=ru_RU.UTF-8 TZ=Cuba
2023年 4月 2日 日曜日 10時47分31秒 JST
воскресенье,  2 апреля 2023 г. 10:47:31 (JST)
Sat Apr  1 21:47:31 CDT 2023
*/
