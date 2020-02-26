#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *ThreadEntry(void *arg){
  (void) arg;

  while(1){
    printf("In ThreadEntry:%lu\n",pthread_self());
    sleep(1);
  }
  return NULL;
}

int main(){
  pthread_t tid;
  pthread_create(&tid,NULL,ThreadEntry,NULL);

  while(1){
    printf("In main:%lu\n",pthread_self());
    pthread_cancel(tid);
    sleep(1);
  }
  return 0;
}

/*int 
 * */
