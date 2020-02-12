#include<stdio.h>

int main(int argc,char*argv[]){
  (void)argc;
  (void)argv;
  extern char **environ;
  for(int i=0;environ[i];i++){
    printf("%s\n",environ[i]);
  }
  return 0;
}
