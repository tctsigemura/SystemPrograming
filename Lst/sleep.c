#include <stdio.h>
#include <unistd.h>
int main() {
  for (;;) {            // 無限ループ
    printf("hello\n");  // hello表示
    sleep(1);           // １秒待つ
  }
  return 0;
}

/* 実行例
% ./a.out
hello
hello
^C                <-- Ctrl-C で止める
*/
