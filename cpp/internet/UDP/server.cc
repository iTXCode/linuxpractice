//先实现UDP版本的服务器

#include<stdio.h>
#include<sys/socket.h>  //socket所用的头文件
#include<netinet/in.h>  //socketaddr_in 结构体的头文件
#include<arpa/inet.h>   //inet.addr的头文件


int main(){
  //1.先创建一个socket
  // AF_INET是一个宏 ,表示使用 ipv4 协议
  //SOCK_DGRAM   表示使用 UDP 协议
  int sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0){
    perror("socket");
    return 1;
  }
  //2.把当前的socket  绑定上一个ip + 端口号
  sockaddr_in addr;   //是一个结构体
  addr.sin_family=AF_INET;
  addr.sin_addr.s_addr = inet_addr("0.0.0.0"); //0.0.0.0将本地所有的ip都包含进来 
  //把点分十进制转换成32位整数
    //设置ip地址
    //ip 地址也是一个整数,也需要转成网络字节序,只不过
    //int_addr 函数自动帮我们转了
  addr.sin_port=htons(9090);
  //端口号必须得先转成网络字节序
  int ret=bind(sock,(sockaddr*)&addr,sizeof(addr));
  if(ret<0){
    perror("bind");
    return 1;
  }
  printf("server start ok!");
  //3.处理服务器收到的请求
  while(ture){
    //1.读取客户端的请求
    recvform();
    //2.根据请求计算响应时间
    //3.把响应写回客户端
    
  }
  return 0;

}
