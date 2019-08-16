#include"myshm.h"
int main(){
  //从共享内存中读数据
  //1.创建打开共享内存对象
  int shmid=CreateShm();
  //2.附加到共享内存上 
  //void *shmat(int shmid, const void *shmaddr, int shmflg);
  char *p=(char*)shmat(shmid,NULL,0);
  //3.直接使用
  printf("reader:%s\n",p);
  return 0;
}
