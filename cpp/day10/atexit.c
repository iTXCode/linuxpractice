#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


//假设 c 语言执行过程，这个过程会写一个文件(临时文件)

void Func(){
    printf("goodbye!\n");
}

int main(){
    atexit(Func);
    return 0;
}
