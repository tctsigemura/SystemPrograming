#include <stdio.h>
extern char **environ;                    // 外部で定義されている
int main(int argc, char *argv[]) {        // 今回はenvpは不要
  for (int i=0; environ[i]!=NULL; i++) {  // NULLが見つかるまで
    printf("%s\n", environ[i]);           // 環境変数を印刷
  }
  return 0;                               // 必ず正常終了
}
/* 実行例
$ ./a.out
LANG=ja_JP.UTF-8
TZ=Japan
HOME=/Users/sigemura
LC_TIME=C
...
 */
