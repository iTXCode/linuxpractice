#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  close(1);
  //关闭标准的输出文件描述符
  int fd=open("test.txt",O_WRONLY);
  //第二个参数决定文件test.txt的打开方式
  fprintf(stderr,"fd=%d\n",stdout->_fileno);
  printf("新的输出:%d\n",stdout->_fileno);
  printf("旧的命令:%d\n",stdout->_fileno);
  //内容在文件中打印出来
  //fprintf(stdout,"新的输出:%d\n",stdout->_fileno);
  //std->_fileno  文件描述符
  printf("fd:%d\n",fd); 
  return 0;
}
