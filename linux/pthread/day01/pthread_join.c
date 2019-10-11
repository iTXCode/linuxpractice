#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

void * ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry\n");
    sleep(1);
  }
  return  NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);  
  printf("In mian Thread\n"); 
  pthread_join(tid,NULL);
  printf("new thread 已经被回收了!\n");
  return 0;
}

