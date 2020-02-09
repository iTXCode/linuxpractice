#include<stdio.h>
#include<unistd.h>

int main(){
  pid_t ret=fork();
  
  if(ret>0){
    printf("father pid:%d,ppid:%d\n",getpid(),getppid());
    sleep(9);
    printf("-------father is die------------\n");
  }else if(ret==0){
    while(1){
      printf("child pid:%d,ppid:%d\n",getpid(),getppid());
      sleep(1);
    }
  }else{
    perror("fork");
    return 1;
  }
  return 0;
}
