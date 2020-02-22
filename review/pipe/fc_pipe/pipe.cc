#include<stdio.h>
#include<unistd.h>
#include<string.h>


int main(){
  int fd[2];

  int ret=pipe(fd);

  if(ret<0){
    perror("pipe");
    return 1;
  }

  ret=fork();
  if(ret>0){
    //写数据
    char buf[1024]="hehe";
    write(fd[1],buf,strlen(buf));
    printf("father write:%s\n",buf);
  }else if(ret==0){
    //读数据
    char buf_output[1024]={0};
    read(fd[0],buf_output,sizeof(buf_output)-1);
    printf("child read:%s\n",buf_output);
  }else{
    perror("fork");
  }

  close(fd[0]);
  close(fd[1]);
  return 0;
}
