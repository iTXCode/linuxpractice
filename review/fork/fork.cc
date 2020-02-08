#include<stdio.h>
#include<unistd.h>

int main(){
  printf("The code belong to father!\n");

  int i=0;
  int j=0;
  printf("j=%d\n",j++);
 
  for(int flag=0;flag<2;flag++){

    pid_t ret=fork();

    printf("i=%d\n",++i);
    printf("The code belong to father and child!\n");

    if( ret>0 ){
      printf("I'm father! my pid:%d my father pid:%d\n",getpid(),getppid());
    }else if(ret==0){
      printf("I'm child! my pid:%d my father pid:%d\n",getpid(),getppid());
    }else{
      perror("fork");
    }

  }
  return 0;
}
