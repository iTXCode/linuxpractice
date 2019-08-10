#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("father pid:%d,ppid=%d\n",getpid(),getppid());
    sleep(9);
    printf("------parent going to die------------\n");
  }else if(pid==0){
    while(1){
  printf("child pid:%d,ppid=%d\n",getpid(),getppid());
    sleep(1);
    }

  }else{
    perror("fork");
    return 1;
  }
  return 0;
}
