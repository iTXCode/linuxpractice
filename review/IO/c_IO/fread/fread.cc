#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main(){
  FILE *fp=fopen("open.txt","r");

  if(!fp){
    printf("fopen error!\n");
  }

  char buf[1024];
  const char*  msg="hello world!\n";
  while(1){
    ssize_t s=fread(buf,1,strlen(msg),fp);

    if(s>0){
      buf[s]=0;
      printf("%s",buf);
    }

    if(feof(fp)){
      break;
    }
  }
  fclose(fp);
  //关闭文件流
  return 0;
}
