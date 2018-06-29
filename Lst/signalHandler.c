#include <unistd.h>
#include <signal.h>
volatile sig_atomic_t flg = 0;        // シグナルハンドラが操作しても良い
void handler(int n) {
  flg = 1;                            // 単純な代入
  write(1, "Ctrl-C\n", 7);            // 非同期シグナル安全な関数の実行
}
int main(int argc, char **argv) {
  int cnt = 0;
  signal(SIGINT, handler);
  while (cnt<3) {
    if (flg) {                        // 単純な参照
      cnt++;
      flg = 0;                        // 単純な代入
    }
  }
  return 0;
}
