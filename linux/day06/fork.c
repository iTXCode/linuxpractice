#include<stdio.h>
#include<unistd.h>


int main(){
  pid_t pid=fork();
  if(pid>0){
    printf("father pid:%d,ppid=%d\n",getpid(),getppid());
  }else if(pid==0){
    printf("child pid:%d,ppid=%d\n",getpid(),getppid());
    sleep(3);
    printf("child pid:%d,ppid=%d\n",getpid(),getppid());
  }else{
    perror("fork");
  }
  return 0;
}
