/*
An example solution to handling the problem of Binary Expression parsing, basically, 
how do we handle Pemdas and order of operations etc. 
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
  int i;
  printf("((((");
  for(i=1;i!=argc;i++){
    if(argv[i] && !argv[i][1]){
      switch(*argv[i]){
          case '(': printf("(((("); continue;
          case ')': printf("))))"); continue;
          case '^': printf(")^("); continue;
          case '*': printf("))*(("); continue;
          case '/': printf("))/(("); continue;
          case '+':
            if (i == 1 || strchr("(^*/+-", *argv[i-1]))
              printf("+");
            else
              printf(")))+(((");
            continue;
          case '-':
            if (i == 1 || strchr("(^*/+-", *argv[i-1]))
              printf("-");
            else
              printf(")))-(((");
            continue;
      }
    }
    printf("%s", argv[i]);
  }
  printf("))))\n");
  return 0;
}
