//#include<stdio.h>
//#include<unistd.h>
//#include<fcntl.h>
//int main(){
//  //打印标准输入/输出/错误的文件描述符
//  printf("stdin:%d\n",stdin->_fileno);
//  printf("stdout:%d\n",stdout->_fileno);
//  printf("sterr:%d\n",stderr->_fileno);
//  //open的返回值叫做 文件描述符
//  int fd=open("./open.txt",O_RDONLY);
//  //参数1：文件名
//  printf("fd=%d\n",fd);
//  return 0;
//}
//
//



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
  int fd=open("./open.txt",O_RDONLY);
  //参数1：文件名
  if(fd<0){
    perror("open");
    return 1;
  } 
  //size_t 无符号的长整形
  //ssize_t 有符号的长整形
  char buf[1024]={0};
  ssize_t n=read(fd,buf,sizeof(buf)-1);
  buf[n]='\0';
  //防止内存访问越界
  printf("%s\n",buf);
  close(fd);
  return 0;
}
