#include"threadpool.hpp"
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

class MyTask:public Task 
{
public:
  MyTask(int id)
  :_id(id)
  {

 }
  ~MyTask(){

  }
  void Run(){
    printf("id=%d\n",_id);
  }
private:
  int _id;
};

int main(){
  ThreadPool pool(10);
  for(int i=0;i<20;i++){
    pool.AddTask(new  MyTask(i));
  }

  while(1){
    sleep(1);
  }
  return 0;
}
