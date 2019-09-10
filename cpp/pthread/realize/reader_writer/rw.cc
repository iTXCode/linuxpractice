#include<pthread.h>
#include<stdio.h>
#include<unistd.h>


int g_count=0;
//一个交易场所


//两中角色
void * Reader(void * arg){
  (void) arg;
  while(1){
    printf("g_count=%d\n",++g_count);
  }
  return NULL;
}

void  *Writer(void *arg){
  (void )  arg;
  int count=0;
  while(1){
  ++count;
  g_count=count;
  sleep(1);
  }
  return NULL;
}
int main(){
  pthread_t  tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Reader,NULL);
  pthread_create(&tid2,NULL,Reader,NULL);
  pthread_create(&tid3,NULL,Reader,NULL);
  pthread_create(&tid4,NULL,Writer,NULL);
  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  return 0;
}
