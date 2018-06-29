// myrm : 簡易 rm コマンド
#include <stdio.h>     // perror のため
#include <unistd.h>    // unlink のため

int main(int argc, char *argv[]) {
  // (1) 使用方法を間違っていないかチェックする
  if (argc<2) {
    fprintf(stderr,"使用方法: %s file ...\n", argv[0]);
    return 1;
  }

  // (2) ファイルの削除（リンクの削除を実行する）
  int err = 0;         // エラーが発生したか
  for (int i=1; i<argc; i++) {
    if (unlink(argv[i])<0) {
      perror(argv[i]);
      err = 1;         // エラーが発生したことを記録して処理は続行する
    }
  }

  return err;
}
