#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// バグ：alarm を使用中に mysleep を使用するとタイマーが解除される
static void alHandler(int n) { }         // 必要以上に見えないように static
unsigned int mysleep(unsigned int seconds) {
  if (seconds==0) return 0;              // alarm(0)は予約解除(誤動作防止)
  sig_t org = signal(SIGALRM, alHandler);// 以前のハンドラを保存
  alarm(seconds);                        // SIGALRMを予約
  pause();                               // シグナルを待つ
  unsigned int r = alarm(0);             // SIGALRMの予約を確実に解除
  signal(SIGALRM, org);                  // ハンドラを復元する
  return r;                              // 残り時間を返す
}

// 以下はテストドライバ
void intHandler(int n) { }               // ^Cでmysleep終了のテスト用

int main() {
  for (int i=0;i<=3;i++) {
    printf("%d秒スリープ開始\n", i);
    int r = mysleep(i);
    printf("スリープ終了（残り時間%d秒）\n", r);
  }
  signal(SIGINT, intHandler);                // ^C用ハンドラを登録
  printf("これから10秒スリープします．\n");
  printf("その間に^Cを入力すると残り時間を表示して終了します．\n");
  printf("\n残り時間%d秒\n", mysleep(10));
  return 0;
}

/* 実行例
%  make
cc -Wall -std=c99 -o mysleep mysleep.c     <--- エラー・警告はなかった
% ./mysleep
0秒スリープ開始
スリープ終了（残り時間0秒）                  <--- ０秒スリープ動作確認OK
1秒スリープ開始
スリープ終了（残り時間0秒）
2秒スリープ開始
スリープ終了（残り時間0秒）
3秒スリープ開始
スリープ終了（残り時間0秒）
これから10秒スリープします．
その間に^Cを入力すると残り時間を表示して終了します．
^C
残り時間7秒                               <--- シグナルで終了の場合OK
*/
