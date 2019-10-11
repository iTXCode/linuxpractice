#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* EntryPthread(void* arg){
(void )arg;
while(1){
  printf("In EntryPthread:%lu\n",pthread_self());
  sleep(1);
}
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,EntryPthread,NULL);
  while(1){
    printf("In main:%lu\n",pthread_self());
    sleep(1);
  }
  return 0;
}
