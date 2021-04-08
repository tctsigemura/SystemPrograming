#include <stdio.h>
#include <unistd.h>                   // alarm, pause のために必要
#include <signal.h>                   // signal のために必要
void handler(int n) {}                // 何もしないハンドラ関数
int main(int argc, char *argv[]) {
  signal(SIGALRM, handler);           // SIGALRMを捕捉に変更する
  alarm(3);
  printf("pause()します\n");
  pause();                            // プロセスが停止する
  printf("pause()が終わりました\n");
  return 0;
}
/* 実行例
$ ./a.out
pause()します
pause()が終わりました         <-- 3秒後表示される
*/
