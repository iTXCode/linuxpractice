#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

int g_count=0;
void * ThreadEntry(void *arg){
  (void) arg;
  while(1){
    printf("In ThreadEntry \n");
    sleep(1);
    g_count++;
  } 
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);
  pthread_detach(tid);
  //分离刚才创建的新线程
  while(1){
    printf("In mian Thread:%d\n",g_count);
    sleep(1);
  }
  return 0;
}

