/*
 * mymv : 簡易 mv コマンド(ファイルを移動するプログラム)
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* (1) 使い方が正しいか確認する */
  if (argc!=3) {
    fprintf(stderr,"使用方法: %s <もとの名前> <新しい名前>\n", argv[0]);
    exit(1);
  }

  /* (2) (1)でargv[1],argv[2]が存在することを確認できたのでrenameを実行する */
  if (rename(argv[1], argv[2])<0) {
    perror(argv[0]);                /* エラーメッセージはプログラム名で妥協 */
    exit(1);
  }

  exit(0);
}
