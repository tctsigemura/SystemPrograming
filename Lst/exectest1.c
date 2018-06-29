#include <stdio.h>         // perror のために必要
#include <unistd.h>        // execve のために必要
extern char **environ;
char *args[] = { "date", NULL };
char *execpath="/bin/date";
int main(int argc, char *argv[], char *envp[]) {
  execve(execpath, args, environ);   // /bin/dateを自分と同じ環境変数で実行
  perror(execpath);                  // ※ execveが戻ってきたらエラー！
  return 1;
}
/* 実行例（英語表示、日本時間で表示される）
$ ./exectest1
Sat Jul 16 22:25:33 JST 2016
*/
