#include<stdio.h>
#include<string.h>

int main(){
  FILE *fp=fopen("myfile","w");
  //myfile 位目标文件,w为写操作
  if(!fp){
    printf("fopen errpr!\n");
  }

  const char *msg="hello  wrold!\n";

  int count=5;
  while(count--){
    fwrite(msg,strlen(msg),1,fp);
  }
  fclose(fp);
  //关闭文件流
  return 0;
}
