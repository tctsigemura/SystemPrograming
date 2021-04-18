#include <stdio.h>                 // perror のため
#include <stdlib.h>                // exit のため
#include <fcntl.h>                 // open のため
#include <unistd.h>                // read,write,close のため

//#define  BSIZ 1                    // !!バッファサイズ：変化させ性能を調べる!!
#define  BSIZ 1024                 // !!バッファサイズ：変化させ性能を調べる!!

int main(int argc, char *argv[]) {
  int fd1;                         // コピー元用のFD
  int fd2;                         // コピー先用のFD
  ssize_t len;                     // 実際に読んだバイト数
  char buf[BSIZ];                  // バッファ

  // ユーザの使い方エラーのチェック
  if (argc!=3) {
    fprintf(stderr, "Usage : %s srcfile dstfile\n", argv[0]);
    return 1;                      // exit(1); と同じ
  }

  // 読み込み用にファイルオープン
  fd1 = open(argv[1], O_RDONLY);
  if (fd1<0) {                     // コピー元のオープンエラーのチェック
    perror(argv[1]);               // エラーメッセージ表示
    return 1;                      // exit(1); と同じ
  }

  // 書き込み用にファイルオープン
  fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
  if (fd2<0) {                     // コピー先のオープンエラーのチェック
    perror(argv[2]);               // エラーメッセージ表示
    return 1;                      // exit(1); と同じ
  }

  // ファイルの書き写し
  while ((len=read(fd1, buf, BSIZ))>0) {
    write(fd2, buf, len);
  }

  close(fd1);
  close(fd2);
  return 0;                        // 正常終了
}
