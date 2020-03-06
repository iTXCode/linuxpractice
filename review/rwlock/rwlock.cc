#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


int g_count=0;

pthread_rwlock_t lock;
void* Reader(void *arg){
  (void) arg;
  while(1){
    pthread_rwlock_rdlock(&lock);
    printf("g_count =%d\n",g_count);
    pthread_rwlock_unlock(&lock);
    sleep(1);
  }
  return NULL;
}

void* Writer(void* arg){
  (void) arg;
  int count=0;
  while(1){
    pthread_rwlock_wrlock(&lock);
    ++count;
    g_count=count;
    pthread_rwlock_unlock(&lock);
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_rwlock_init(&lock,NULL);
  pthread_t tid1,tid2,tid3,tid4;
  pthread_create(&tid1,NULL,Reader,NULL);
  pthread_create(&tid3,NULL,Reader,NULL);
  pthread_create(&tid4,NULL,Reader,NULL);
  pthread_create(&tid2,NULL,Writer,NULL);

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_rwlock_destroy(&lock);
  return 0;
}
