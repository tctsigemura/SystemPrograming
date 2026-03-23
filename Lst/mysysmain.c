/*
 *  mysysmain.c : system 関数のテストドライバ
 */

#include <stdio.h>
#include <stdlib.h>    // exit, system のため
#include "mysystem.h"  // インタフェース

// テストドライバ（mysystem()関数動作テスト用の仮のmain）
int main(int argc, char *argv[]) {
  if (argc!=2) {
    fprintf(stderr, "使い方 : %s コマンド文字列\n", argv[0]);
    return 1;
  }
  printf("mysystem:\n");
  int r = mysystem(argv[1]);            // mysystemを実行してみる
  if (r<0) perror(argv[1]);             // 親プロセスでエラーが発生した
  printf("retval = %08x\n", r);         // mysystemが返した値

  printf("system:\n");
  int s = system(argv[1]);              // 比較のために本物systemを実行
  if (s<0) perror(argv[1]);             // 親プロセスでエラーが発生した
  printf("retval = %08x\n", s);         // systemが返した値
  return 0;
}

