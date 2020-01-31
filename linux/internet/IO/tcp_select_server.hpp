#pragma once
#include<vector>
#include<set>
//使用set的原因:需要高效的插入和删除.
//需要方便的找到最大元素
#include<unordered_set>
#include"tcp_socket.hpp"


//lhs左操作数
//rhs表示右操作数
bool operator<(const TcpSocket& lhs,const TcpSocket& rhs){
  return lhs.GetFd()<rhs.GetFd();
}

//select 这个函数用起来很不方便,所以我们封装成一个类来使用
//提供以下几个操作
//文件描述符的管理器,这个管理器中包含的额socket 就是使用select来管理的socket
//1.新增一个文件描述符
//2.删除一个文件描述符
//3.等待操作  等待管理的文件描述符就绪(指考虑就绪的情况)
class Selector{
  public:
    void Add(const TcpSocket& sock){

    }

    void Del(const TcpSocket& sock){

    }


    void Wait(std::vector<TcpSocket>* output){

    }

    //wait返回的时候需要告诉调用者那那些文件描述符就绪了
    
  private:
    //使用一个数据结构把我们需要的socket存起来
    //要求TcpSocket类能够支持 比较操作 (operator <)
    std::set<TcpSocket> socket_set;
};
