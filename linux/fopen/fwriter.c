#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  FILE *fd=fopen("myfile.md","w");
  if(!fd){
    perror("fopen");
  }
  const char* buf={"将军的荣耀\n"};
  fwrite(buf,strlen(buf),1,fd);
  fclose(fd);
  return 0;
}
