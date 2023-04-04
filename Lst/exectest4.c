#include <stdio.h>         // perror のために必要
#include <unistd.h>        // execve のために必要
extern char **environ;
char *args[] = { "echo", "aaa", "bbb", NULL };  // "$ echo aaa bbb" に相当
char *execpath="/bin/echo";
int main(int argc, char *argv[], char *envp[]) {
  execve(execpath, args, environ);   // /bin/echoを自分と同じ環境変数で実行
  perror(execpath);                  // execveが戻ってきたらエラー！
  return 1;
}
/* 実行例
% ./exectest4
aaa bbb                 <--- /bin/echo の出力
*/
