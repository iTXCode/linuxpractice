#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<thread>
#include<mutex>
#include<atomic>  //原子操作头文件

//C++ 中自带了std::thread 
//c++开始，把线程直接纳入到标准库之中
//std::thread 类
//int count=0;//这种方式引起线程不安全的问题
//使用原子操作解决问题
std::atomic_int count(0); //调用构造函数
//曾经 ++ 普通变量,步骤分为3个部分
//现在的 原子操作,把这三个步骤合并成一个了
//非常高效
//
//原子操作本质上也是锁,只不过是 CPU 指令级别的锁
//这样的锁本质为    自旋锁

 std::mutex lock; //这个变量的初始化和释放都包含在构造函数
// 和析构函数中了
//函数传参的时候直接在std::thread 定义的对象中添加即可
void Headler(std::shared_ptr<int> p){
  std::shared_ptr<int>  p3(p);
  
}

int main(){
  //std::thread 构造函数用到的语法  变长参数模板
  std::shared_ptr<int>  p(new int[10]);
  std::shared_ptr<int> p2(p);
  std::thread t(Headler,p);
  std::thread t1(Headler,p2);
  t.join();
  t1.join();
  printf("count =%d \n",(int)count);
  return 0;
}
