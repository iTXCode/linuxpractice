#include<pthread.h>
#include<unistd.h>
#include<stdio.h>


void * ThreadEntry(void *arg){
 int *p= (int *) arg;
 //arg->count的地址
  while(1){
    printf("In ThreadEntry \n");
    ++*p;
    sleep(1);

  } 
}

int main(){
  int count=0;
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,&count);
  pthread_detach(tid);
  //分离刚才创建的新线程
  while(1){
    printf("In mian Thread:%d\n",count);
    sleep(1);
  }
  return 0;
}

