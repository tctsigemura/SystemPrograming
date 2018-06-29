#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t flg = 0;  // ハンドラと main で共通のフラグ

void handler3(int sig) {        // 最後のハンドラ
  flg = 1;                      // フラグを立てる
  write(1, "last\n", 5);
}

void handler2(int sig) {        // 第２のハンドラ
  signal(SIGINT, handler3);     // 最後のハンドラに切替える
  write(1, "2nd\n", 4);
}

void handler1(int sig) {        // 第１のハンドラ
  signal(SIGINT, handler2);     // 第２のハンドラに切替える
  write(1, "1st\n", 4);
}

int main() {
  signal(SIGINT, handler1);     // 最初は第１のハンドラを登録する
  while (flg==0) {              // フラグが変化するまでループする
  }
  return 0;
}

/* 実行例
$ a.out
^C1st
^C2nd
^Clast
$
*/
