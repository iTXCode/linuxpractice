#include<stdio.h>
#include<string.h>

int main(){
  FILE * fp=fopen("myfile.md","r");
  if(!fp){
    perror("fopen");
  }
  char buf[1024]={0};
  const char*msg={"将军的荣耀\n"};
  while(1){
    size_t s=fread(buf,1,strlen(msg),fp);
    if(s>0){
      buf[s]=0;
      printf("%s",buf);
    }
    if(feof(fp)){
      break;
    }
  }
  fclose(fp);
  return 0;
}
