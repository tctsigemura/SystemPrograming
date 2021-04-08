#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// バグ：alarm を使用中に mysleep を使用するとタイマーが解除される
static void handler(int n) {    // 必要以上に見えないように static にする
}

unsigned int mysleep(unsigned int seconds) {
  if (seconds<=0) return 0;              // 誤動作防止
  sig_t org = signal(SIGALRM, handler);
  alarm(seconds);                        // SIGALRMを予約
  pause();                               // シグナルを待つ
  signal(SIGALRM, org);                  // ハンドラを復元する
  return alarm(0);                       // 他のシグナルで再開する場合に
}                                        //   残り時間を返すことができる

int main() {
  for (;;) {
    printf("hello\n");
    mysleep(1);
  }
  return 0;
}

/* 実行例
$ ./a.out
hello                 <---- hello が一秒に一度表示される．
hello
hello
hello
hello
^C                    <---- Ctrl-C でプログラムを終了する．
$
*/
