/*
 * mymkdir : 簡易 mkdir コマンド
 */
#include <stdio.h>     /* perror のため */
#include <stdlib.h>    /* exit のため   */
#include <sys/types.h> /* mkdir のため  */
#include <sys/stat.h>  /* mkdir のため  */

int main(int argc, char *argv[]) {
  int i;
  int err = 0;         /* エラーが発生したか */

  if (argc<2) {
    fprintf(stderr,"使用方法: %s directory ...\n", argv[0]);
    exit(1);
  }

  for (i=1; i<argc; i++) {
    if (mkdir(argv[i],0755)<0) {
      perror(argv[i]);
      err = 1;
    }
  }

  exit(err);          // return err; でも良い
}
