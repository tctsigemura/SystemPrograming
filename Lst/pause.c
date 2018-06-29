#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void handler(int n) {}         // 何もしないハンドラ関数
int main() {
  signal(SIGINT, handler);     // SIGINTを捕捉に変更する
  pause();                     // 1回目の　Ctrl-C を待つ
  pause();                     // 2回目の　Ctrl-C を待つ
  pause();                     // 3回目の　Ctrl-C を待つ
  return 0;                    // Ctrl-C 3回で終了する
}
/* 実行例
$ a.out
^C^C^C$       <-- Ctrl-C 3回で終了した
*/
