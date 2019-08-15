#include<stdio.h>

void fun(){
  FILE* fp=fopen("test.txt","w");
  //在打开文件到关系文件的过程中,可能导致
  //提前返回而使得文件未关闭，导致文件泄露
  char buf[1024]={0};
  //该文件中一个元素是一个字节,一共1024个元素
  //int n=fwrite(buf,1,1024,fp);
  //该文件中一个元素两个字节，一共512个元素
  int n= fwrite(buf,2,512,fp);
  //buf指向内存的指针
  fclose(fp);
}

int main(){
  fun();
  return 0;
}
