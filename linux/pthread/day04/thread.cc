#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<thread>
#include<mutex>


//C++ 中自带了std::thread 
//c++开始，把线程直接纳入到标准库之中
//std::thread 类
 std::mutex lock; //这个变量的初始化和释放都包含在构造函数
// 和析构函数中了
//函数传参的时候直接在std::thread 定义的对象中添加即可
void Headler(){
  while(1){
    lock.lock();
    printf("hehe\n");
    lock.unlock();
    sleep(1);
  }
}

int main(){
  //std::thread 构造函数用到的语法  变长参数模板
  std::thread t(Headler);
  t.join();
  return 0;
}
