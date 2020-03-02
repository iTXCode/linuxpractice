#include<stdio.h>
#include<signal.h>

volatile int flag=1;


//volatile作用
//告诉编译器,这个变量必须每次都从内存中读取
//不能优化到寄存器中
//volatile 的功能称为"保持内存的可见性"
void MyHandler(int sig){
  (void) sig;
  flag=0;
}

int main(){
  signal(1,MyHandler);

  while(flag);
  return 0;
}
