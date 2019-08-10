#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
  size_t fd;
  fd=open("ps.out",O_WRONLY|O_CREAT|O_TRUNC,0644);
 //参数含义:文件名为ps.out,以只写方式打开，文件不存在
 //就创建，如果存在就指定为0，指定以0644权限打开
  if(fd<0){
    perror("open ps.out error");
    exit(1);
  }
  dup2(fd,STDOUT_FILENO);
  execlp("ps","ps","ax",NULL);

 // close(fd);
  return 0;
}
