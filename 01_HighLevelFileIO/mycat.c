// mycat.c : 複数のファイルを stdout へ連続出力
#include <stdio.h>
#include <stdlib.h>  // exit のため

// ifp から ofp にコピー
void fileCopy(FILE *ifp, FILE *ofp) {
  int c;
  while ((c=getc(ifp))!=EOF)
    putc(c, ofp);
}

int main(int argc, char *argv[]) {
  if (argc==1)                          // ファイルが指定されていない
    fileCopy(stdin, stdout);            //   stdin から stdout へコピー
  else                                  // ファイルが指定されている
    for (int i=1; i<argc; i++) {        //   全てのファイルについて
      FILE *fp = fopen(argv[i], "r");   //     オープンして
      if (fp==NULL) {                   //     エラーチェックして
	perror(argv[i]);
	exit(1);
      }
      fileCopy(fp, stdout);             //     ファイルから stdout へコピー
      fclose(fp);                       //     忘れずクローズ
    }
  return 0;
}
