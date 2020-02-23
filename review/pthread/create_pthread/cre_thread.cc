#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry %lu\n",pthread_self());
    sleep(1);
  }
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);

  while(1){
    printf("In main Thread%lu\n",pthread_self());
    sleep(1);
  }

  return 0;
}
