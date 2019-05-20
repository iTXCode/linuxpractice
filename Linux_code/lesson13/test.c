#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

int main(){
 //使用pipe函数创建一
 //
  int fd[2];
  int ret=pipe(fd);
  if(ret<0){
    perror("pipe");
    return 1;
  }
  
  
  //fd[0]->读数据
  //fd[1]->写数据
  


  ////管道使用完后要及时关闭文件描述符
  close(fd[0]);
  close(fd[1]);
  return 0;
}
