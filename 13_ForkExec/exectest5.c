#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>    // open のために必要

extern char **environ;
char *args[] = { "echo", "aaa", "bbb", NULL };    // "$ echo aaa bbb" に相当
char *execpath="/bin/echo";
char *outfile="aaa.txt";

int main(int argc, char *argv[], char *envp[]) {
  close(1);                                       // 標準出力をクローズする
  int fd = open(outfile,                          // 標準出力を "aaa.txt" と
		O_WRONLY|O_CREAT|O_TRUNC, 0644);  //   してオープンしなおす
  if (fd<0) {                                     // オープンできなかった
    perror(outfile);                              //   エラーメッセージを出力
    return 1;                                     //   エラー終了
  }
  if (fd!=1) {                                    // 標準出力以外になってる
    fprintf(stderr, "何か変！\n");                //   原因が分からないが...
    return 1;                                     //   何か変なのでエラー終了
  }
  execve(execpath, args, environ);                // /bin/echo を実行
  perror(execpath);                               // exec が戻ってきたらエラー！
  return 1;
}

/* 実行例
$ exectest5                 <-- echo が実行されたはずなのに何も出力されない
$ cat aaa.txt               <-- "aaa.txt" に
aaa bbb                     <--   echo の出力が保存されていた
*/
