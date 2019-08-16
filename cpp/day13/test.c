#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
  close(1);
  int fd=open("test.txt",O_RDONLY);
  fprintf(stderr,"fd=%d\n",fd);
  //
  printf("")
  close(fd);
  return 0;
}
