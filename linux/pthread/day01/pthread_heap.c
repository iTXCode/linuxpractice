#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


void * ThreadEntry(void *arg){
  int *p=  (int *) arg;
  while(1){
    printf("In ThreadEntry \n");
    ++*p;
    sleep(1);
  } 
}

int main(){
  int *p=(int* )malloc(4);
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,p);
  pthread_detach(tid);
  //分离刚才创建的新线程
  while(1){
    printf("In mian Thread%d\n",*p);
    sleep(1);
  }
  return 0;
}

