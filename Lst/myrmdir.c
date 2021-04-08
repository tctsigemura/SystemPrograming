//
// myrmdir : 簡易 rmdir コマンド
//
#include <stdio.h>     // perror のため
#include <unistd.h>    // rmdir のため

int main(int argc, char *argv[]) {
  // (1) 使用方法を間違っていないかチェックする
  if (argc<2) {
    fprintf(stderr,"使用方法: %s directory ...\n", argv[0]);
    return 1;
  }

  // (2) ディレクトリを削除する
  int err = 0;         // エラーが発生したか
  for (int i=1; i<argc; i++) {
    if (rmdir(argv[i])<0) {
      perror(argv[i]);
      err = 1;
    }
  }

  return err;
}
