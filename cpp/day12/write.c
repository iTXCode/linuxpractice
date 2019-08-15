
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
  int fd=open("./open.txt",O_WRONLY | O_CREAT);
  //参数1：文件名
  //参数2：打开文件的方式
  if(fd<0){
    perror("open");
    return 1;
  }
  //读文件
//  //size_t 无符号的长整形
//  //ssize_t 有符号的长整形
//  char buf[1024]={0};
//  ssize_t n=read(fd,buf,sizeof(buf)-1);
//  buf[n]='\0';
//  //防止内存访问越界
//
  //写文件
  char buf[1024]="hehe";
  ssize_t n=write(fd,buf,strlen(buf));
  //分段书写日志
  buf[n]='\n';//double check
  printf("%d\n",n);
  printf("%s\n",buf);
  close(fd);
  return 0;
}
