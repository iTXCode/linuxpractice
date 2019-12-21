#include"udp_server.hpp"
//void Echo(const std::string& req,std::string* resp){
//  *resp=req;//回显服务器，请求是什么，就返回什么
//}
//
int main(){
  UdpServer server;
  //lambda 表达式 本质上是一个 匿名函数
  //[]()->int {}
  //[] 
  server.Start("0.0.0.0",9090,[](const std::string &req,
        std::string* resp){*resp=req;});
//server.Start("0.0.0.0",9090,Echo);//c++反对函数指针
  return 0;
}

/*
匿名结构体作用:
1.一般没什么用
2.没有什么地方能够用到匿名结构体
c++11 引入的匿名函数就是所谓的Lambda表达式
[] 表示我是一个lambda,[]中可以放什么内容?
() 表示lambda表达式的参数
{} 表示函数体
如果需要返回值的话
在参数的后面写一个-> 箭头后面填写返回值类型 
*/
