#include <stdio.h>         // perror のために必要
#include <unistd.h>        // execve のために必要
#include <stdlib.h>        // putenv のために必要
extern char **environ;
char *args[] = { "date", NULL };
char *execpath="/bin/date";
int main(int argc, char *argv[], char *envp[]) {
  putenv("LC_TIME=ja_JP.UTF-8");     // 自分の環境変数を変更する
  execve(execpath, args, environ);   // /bin/dateを自分と同じ環境変数で実行
  perror(execpath);                  // execveが戻ってきたらエラー！
  return 1;
}
/* 実行例（日本語表示、日本時間で表示される）
% ./exectest3
2023年 4月 2日 日曜日 09時24分29秒 JST
*/
