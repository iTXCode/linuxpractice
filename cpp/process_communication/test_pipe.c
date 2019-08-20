#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
  //使用pipe函数创建一对文件描述符,通过这一对文件描述符就能
    //操作内核中的管道
    int fd[2];
  int ret=pipe(fd);//管道的使用
  if(ret<0){
    perror("pipe");
    return 1;
  }
  //fd[0]-->读数据
  //fd[1]-->写数据
  char buf[1024]="hehe";
  write(fd[1],buf,strlen(buf));
  char buf_output[1024]={0};
  ssize_t n=read(fd[0],buf_output,sizeof(buf_output-1));
  //sizeof(buf_output-1)的原因是防止内存访问越界
  buf_output[n]='\0';//double check
  //C风格的字符串以\0结束
  printf("%s\n",buf_output);
  //管道使用完成后,需要及时关闭文件描述符
  close(fd[0]);
  close(fd[1]);
  return 0;
}
