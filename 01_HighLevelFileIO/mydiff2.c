// mydiff.c : 異なる最初の行を表示する
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 100

// 使用方法を表示して終了する関数
void usage(char *cmd) {
  fprintf(stderr, "Usage: %s <file1> <file2>\n", cmd);
  exit(1);
}

// エラーチェック付きの fopen
FILE *eOpen(char *fname, char *mode) {
  FILE *fp = fopen(fname, mode);
  if (fp==NULL) {
    perror(fname);
    exit(1);
  }
  return fp;
}

// 異なる行を表示する
void printDiffLine(int l, char *line1, char *line2) {
  printf("%d行\n", l);
  printf("> %s", line1);
  printf("---\n");
  printf("> %s", line2);
  exit(1);
}

int main(int argc, char *argv[]) {
  char buf1[MAXLINE];
  char buf2[MAXLINE];

  if (argc!=3) usage(argv[0]);

  FILE *fp1 = eOpen(argv[1], "r");
  FILE *fp2 = eOpen(argv[2], "r");

  for (int ln=1; fgets(buf1, MAXLINE, fp1)!=NULL && 
                 fgets(buf2, MAXLINE, fp2)!=NULL;   ln++) {

    if (strcmp(buf1, buf2)!=0)
      printDiffLine(ln, buf1, buf2);
  }

  // ファイルは自動的にクローズされる
  return 0;
}
