#include <stdio.h>                             // 入出力のために必要
#include <stdlib.h>                            // exit のために必要

// err_exit : ファイルのオープンに失敗したときエラーメッセージを表示し終了
void err_exit(char *prog, char *fname) {
    fprintf(stderr,                            // 標準エラー出力に
	    "%s : can't open %s\n",            // エラーメッセージを表示し
	    prog, fname);
    exit(1);                                   // エラー終了
}

int main(int argc, char *argv[]) {
  FILE *fps;                                   // コピー元ファイル用
  FILE *fpd;                                   // コピー先ファイル用
  int  ch;                                     // コピー時使用

  if (argc != 3) {                             // 引数の個数が予定と異なる
    fprintf(stderr,                            // 標準エラー出力に
	    "Usage: %s <srcfile> <dstfile>\n", // 使用方法を表示して
	    argv[0]);
    exit(1);                                   // エラー終了
  }

  if ((fps = fopen(argv[1], "rb"))==NULL) {    // コピー元のオープン失敗
    err_exit(argv[0], argv[1]);
  }

  if ((fpd = fopen(argv[2], "wb"))==NULL) {    // コピー元のオープン失敗
    err_exit(argv[0], argv[2]);
  }

  while((ch=getc(fps)) != EOF) {               // EOF になるまで
    putc(ch ,fpd);                             // 1バイト毎のコピー
  }

  fclose(fps);                                 // ファイルクローズ
  fclose(fpd);
  
  return 0;                                    // 正常終了
}
