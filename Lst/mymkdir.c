//
// mymkdir : 簡易 mkdir コマンド
//
#include <stdio.h>     // perror のため
#include <sys/types.h> // mkdir のため
#include <sys/stat.h>  // mkdir のため

int main(int argc, char *argv[]) {
  // (1) 使用方法を間違っていないかチェックする
  if (argc<2) {
    fprintf(stderr,"使用方法: %s directory ...\n", argv[0]);
    return 1;
  }

  // (2) ディレクトリを作成する
  int err = 0;         // エラーが発生したか
  for (int i=1; i<argc; i++) {
    if (mkdir(argv[i],0755)<0) {
      perror(argv[i]);
      err = 1;
    }
  }

  return err;
}
