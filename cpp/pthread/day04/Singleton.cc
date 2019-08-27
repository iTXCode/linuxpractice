#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<thread>
#include<mutex>
#if 0
//饿汉模式
template<typename  T>

class Singleton{
  public:
    static T* Instance (){
      return _inst;
    } 
  private:
    static T _inst;
};
#endif



//懒汉模式
template <typename  T>
class Singleton{
  public:
    static T* Instance(){
      if(_inst==NULL){
        //优化方法，不判断直接加锁效率低下
        //不判断的话，每次都需要加锁解锁
        _mtx.lock();
        if(_inst==NULL){
          _inst=new T();
        }
        _mtx.unlock();
      }
      return _inst;
    }
  private:
    volatile  static T* _inst=NULL;
    //加上volatile 目的告诉编译器 不需要优化
    static std:: mutex _mtx;
};



//1.线程安全问题(加锁，锁放到哪里)
//2.加锁之后的效率问题(双重if)
//3.volatile

























