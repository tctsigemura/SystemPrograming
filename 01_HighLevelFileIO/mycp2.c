#include <stdio.h>                             // 入出力のために必要
#include <stdlib.h>                            // exit のために必要

// 使用方法を表示して終了する関数
void usage(char *cmd) {
  fprintf(stderr, "Usage: %s <srcfile> <dstfile>\n", cmd);
  exit(1);
}

// エラーチェック付きの拡張 fopen 関数
FILE *eOpen(char *fname, char *mode) {
  FILE *fp= fopen(fname, mode);
  if (fp==NULL) {
    perror(fname);
    exit(1);
  }
  return fp;
}

// mycat から流用したファイルコピー関数
void fileCopy(FILE *ifp, FILE *ofp) {
  int c;
  while ((c=getc(ifp))!=EOF)
    putc(c, ofp);
}

int main(int argc, char *argv[]) {
  if (argc != 3) usage(argv[0]);               // 引数の個数が予定と異なる

  FILE *fps = eOpen(argv[1], "rb");            // ファイルのオープン
  FILE *fpd = eOpen(argv[2], "wb");

  fileCopy(fps, fpd);                          // ファイルのコピー

  fclose(fps);                                 // ファイルクローズ
  fclose(fpd);
  
  return 0;                                    // 正常終了
}
