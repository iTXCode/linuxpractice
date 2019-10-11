#include<stdio.h>
#include<unistd.h>


int main(){
  int i=0;
  for(;i<2;i++){
    pid_t ret=fork();
    char ch='=';
    if(ret>0){
      printf("%c  ",ch);
    }else if(ret==0){
      printf("%c  ",ch);
    }else{
      perror("fork");
    }
    printf("%d\n",i);
  }
  return 0;
}
