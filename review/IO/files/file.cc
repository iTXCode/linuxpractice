#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
  printf("stdin:%d\n",stdin->_fileno);
  printf("stdout:%d\n",stdout->_fileno);
  printf("stderr:%d\n",stderr->_fileno);

  int fd=open("open.txt",O_RDONLY);

  /*open返回值
   * 成功返回,响应的文件描述符
   * 失败返回-1
   * */
  printf("fd:%d\n",fd);
  return 0;
}
