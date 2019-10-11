#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *EntryPthread(void *arg){
  (void)  arg;
  int count=5;
  while(count--){
    printf("In EntryPthread!\n");
  }
  pthread_exit(NULL);
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,EntryPthread,NULL);
  while(1){
    printf("In main!\n");
    sleep(1);
  } 
  return 0;
}
