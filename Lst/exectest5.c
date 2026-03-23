#include <stdio.h>         // perror のために必要
#include <unistd.h>        // execl のために必要
#include <fcntl.h>         // open のために必要
char *execpath="/bin/echo";
char *outfile="aaa.txt";
int main(int argc, char *argv[], char *envp[]) {
  close(1);                                      // 標準出力をクローズする
  int fd = open(outfile, 
		O_WRONLY|O_CREAT|O_TRUNC, 0644); // 標準出力をオープンしなおす
  if (fd!=1) {                                   // 標準出力以外になってる
    fprintf(stderr, "something is wrong\n");     //   原因が分からないが...
    return 1;                                    //   何か変なのでエラー終了
  }
  execl(execpath, "echo", "aaa", "bbb", NULL);   // /bin/echoを実行
  perror(execpath);                              // execlが戻ったらエラー！
  return 1;
}
/* 実行例
% ./exectest5               <-- echo が実行されたはずなのに何も出力されない
% cat aaa.txt               <-- "aaa.txt" に
aaa bbb                     <--   echo の出力が保存されていた
*/
