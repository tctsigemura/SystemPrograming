#include <stdio.h>                             // 入出力のために必要
#include <stdlib.h>                            // exit のために必要

void fileCopy(FILE *ifp, FILE *ofp) {          // mycat から流用
  int c;                                       // int 型にする必要がある
  while ((c=getc(ifp))!=EOF)
    putc(c, ofp);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {                             // 引数の個数が予定と異なる
    fprintf(stderr,                            // 標準エラー出力に
	    "Usage: %s <srcfile> <dstfile>\n", // 使用方法を表示して
	    argv[0]);
    exit(1);                                   // エラー終了(return 1; でも同じ)
  }

  FILE *fps = fopen(argv[1], "rb");            // バイナリモードでオープン
  if (fps == NULL) {                           // コピー元のオープン失敗
    perror(argv[1]);                           // オープン失敗の原因を表示
    exit(1);                                   // エラー終了(return 1; でも同じ)
  }

  FILE *fpd = fopen(argv[2], "wb");            // バイナリモードでオープン
  if (fpd == NULL) {                           // コピー先のオープン失敗
    perror(argv[2]);                           // オープン失敗の原因を表示
    exit(1);                                   // エラー終了(return 1; でも同じ)
  }
  
  fileCopy(fps, fpd);                          // ファイルのコピー

  fclose(fps);                                 // ファイルクローズ
  fclose(fpd);
  
  return 0;                                    // 正常終了
}
