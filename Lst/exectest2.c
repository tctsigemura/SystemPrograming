#include <stdio.h>         // perror のために必要
#include <unistd.h>        // execve のために必要
char *args[] = { "date", NULL };
char *envs[] = { "LC_TIME=ja_JP.UTF-8", "TZ=Cuba", NULL};
char *execpath="/bin/date";
int main(int argc, char *argv[], char *envp[]) {
  execve(execpath, args, envs);      // /bin/dateを上記の環境変数で実行
  perror(execpath);                  // execveが戻ってきたらエラー！
  return 1;
}
/* 実行例（日本語表示、キューバ時間で表示される）
% ./exectest2
2023年 4月 1日 土曜日 20時25分52秒 CDT
*/
