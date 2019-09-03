//线程分离函数


#include<stdio.h>
#include<pthread.h>
#include<unistd.h>


void * EntryPthread(void *arg){
  (void)arg;
  int count=5;
  while(count--){
    printf("In EntryPthread\n");
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,EntryPthread,NULL);
  pthread_detach(tid);
  int m_count=5;
  while(m_count--){
    printf("In main!\n");
    sleep(1);
  }
  return 0;
}
