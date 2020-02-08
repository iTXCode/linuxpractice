#include<stdio.h>
#include<unistd.h>

int main(){
  printf("The code belong to father!\n");
 
  for(int flag=0;flag<2;++flag){

    int j=0;

    printf("j=%d\n",j);

    ++j;
    pid_t ret=fork();


    printf("The code belong to father and child!\n");

    if( ret>0 ){
      printf("I'm father! my pid:%d my father pid:%d\n",getpid(),getppid());
      sleep(2);
    }else if(ret==0){
      printf("I'm child! my pid:%d my father pid:%d\n",getpid(),getppid());
      sleep(4);
    }else{
      perror("fork");
    }

  }
  return 0;
}
