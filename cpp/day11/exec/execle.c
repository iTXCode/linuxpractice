#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
  pid_t ret=fork();
  if(ret==0){
    char  *env[]={"AAA=BBB",NULL,};
    printf("before exele\n");
    execle("./aaa","./aaa",NULL,env);
  }
  wait(NULL);
  printf("after exece\n");
  return 0;
}
