/*
 * myrmdir : 簡易 rmdir コマンド
 */
#include <stdio.h>     /* perror のため */
#include <stdlib.h>    /* exit のため   */
#include <unistd.h>    /* rmdir のため */

int main(int argc, char *argv[]) {
  int i;
  int err = 0;         /* エラーが発生したか */

  if (argc<2) {
    fprintf(stderr,"使用方法: %s directory ...\n", argv[0]);
    exit(1);
  }

  for (i=1; i<argc; i++) {
    if (rmdir(argv[i])<0) {
      perror(argv[i]);
      err = 1;
    }
  }

  exit(err);
}
