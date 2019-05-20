#include<stdio.h>
#include<unistd.h>

extern int add(int x,int y){
  return  x+y;
}

int main(){
  int ret = add (10,20);
  printf("hehe\n");
  printf("%d\n",ret);
  return 0;
}
