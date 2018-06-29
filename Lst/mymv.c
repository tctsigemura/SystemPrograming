//
// mymv : 簡易 mv コマンド(ファイルを移動するプログラム)
//
#include <stdio.h>  // perror と rename のため

int main(int argc, char *argv[]) {
  // (1) 使い方が正しいか確認する
  if (argc!=3) {
    fprintf(stderr,"使用方法: %s <もとの名前> <新しい名前>\n", argv[0]);
    return 1;
  }

  // (2) ファイルの移動を行う
  if (rename(argv[1], argv[2])<0) {
    perror(argv[0]);                // エラーメッセージはプログラム名で妥協
    return 1;
  }

  return 0;
}
