#include<stdio.h>

int main(int argc,char *argv[],char *env[]){
  for(int i=0;env[i];i++){
    printf("%s\n",env[i]);
  }
  printf("参数个数:%d\n",argc);//输出你执行指令的个数
  printf("%s\n",*argv);//打印出你的执行指令
  return 0;
}
