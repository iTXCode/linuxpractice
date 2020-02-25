#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *EntryThread(void* arg){
  (void) arg;
  int count=4;
  while(count--){
    printf("In EntryThread:%lu\n",pthread_self());
    sleep(1);
  }
 pthread_exit(NULL);
  printf("该线程已经回收!\n");
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,EntryThread,NULL);
 
  pthread_detach(tid);
 
  int count=6;
  while(count--){
    printf("In main:%lu\n",pthread_self());
    sleep(1);
  }

  int ret=pthread_join(tid,NULL);
  if(ret!=0){
    printf("pthread_join执行出错\n");
    printf("错误码ret=%d\n",ret);
  }
  return 0;
}
