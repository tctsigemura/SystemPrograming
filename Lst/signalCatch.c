#include <signal.h>

void handler(int n) {       // シグナルハンドラ（プロトタイプ宣言どおり）
  ...                       // シグナル処理
}

int main() {
  ...
  signal(SIGINT, handler);  // ここから（void f(int)型の関数を引数にする）
  ...                      
  signal(SIGINT, SIG_DFL);  // ここまで
  ...
}
