#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
 pid_t ret=fork();
 
 if(ret<0){
   perror("fork");
   return 1;
 }

 if(ret==0){
   printf("child1 ppid:%d pid:%d\n",getppid(),getpid());
   exit(0);
 }

 ret=fork();

 if(ret==0){
   printf("child2 ppid:%d pid:%d\n",getppid(),getpid());
   exit(0);
 }

  printf("father pid:%d\n",getpid());
  ret=wait(NULL);
  printf("wait1:%d\n",ret);
  ret=wait(NULL);
  printf("wait2:%d\n",ret);
  ret=wait(NULL);
  printf("wait3:%d\n",ret);
  return 0;
}
