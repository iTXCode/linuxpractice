#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
  pid_t ret=fork();
  if(ret<0){
    perror("fork");
    return 0;
  }

  if(ret==0){
    exit(0);
  }

  ret=fork();
  if(ret==0){
    exit(0);
  }

  wait(NULL);
  while(1){
    sleep(1);
  }
  return 0;
}
