#include"udp_client.hpp"
#include<iostream>
#include<stdlib.h>
//客户端发起请求,接收客户端发来的响应

int main(int argc,char* argv[]){
  if(argc!=3){
    printf("Usage ./client [ip] [port]");
    return 1;
  }
  

  UdpClient client(argv[1],atoi( argv[2] )); //构造参数位客户端的IP和端口号
  while(true){
      std::string word;
      std::cout<<"请输入您要查询的单词:";
      std::cin>>word;

      if(!std::cin){
        std::cout<<"Good Bye"<<std::endl;
        break; 
      }
      client.SendTo(word);
      std::string result;
      client.RecvFrom(&result);
      std::cout<<word<<"意思为:"<<result<<std::endl;
  }
  return 0;
}
