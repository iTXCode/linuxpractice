#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
  pid_t ret=fork();
  if(ret==0){
    printf("before exelcp\n");
    execlp("ls","ls","/",NULL);
  }
  wait(NULL);
  printf("after execlp\n");
  return 0;
}
