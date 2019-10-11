#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* EntryPthread(void * arg){
  (void )arg;
  int count=5;
  while(count--){
    printf("In EntryPthread:%lu\n",pthread_self());
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,EntryPthread,NULL);
  printf("In main:%lu\n",pthread_self());
  pthread_join(tid,NULL);
  printf("线程资源已经回收了！\n");
  return 0;
}
