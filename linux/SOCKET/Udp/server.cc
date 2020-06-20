#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>


int main(){
  //先创建一个socket文件
  //AF_INET表示的是IPV4协议
  //SOCK_DGRAM表示使用UDP协议
  int sock=socket(AF_INET,SOCK_DGRAM,0);

  if(sock<0){
    perror("socket");
  }

  //bind()函数的使用:绑定一个IP和端口号
  
  sockaddr_in addr;
  addr.sin_family=AF_INET; 
  addr.sin_addr.s_addr=inet_addr("0.0.0.0");
  addr.sin_port=htons(9090);
  //将端口号的本机字节序转成网络字节序
  int ret=bind(sock,(sockaddr*)&addr,sizeof(addr));

  if(ret<0){
    perror("bind!");
    return  1;
  }

  printf("server start ok!\n");
  while(true){
    //服务器开启之后一致处于待连接状态
    //1.读取客户端收到的请求
    sockaddr_in  peer;
    char buf[1024]={0};
    socklen_t len=sizeof(peer);
    //用于存储接收到的客户端的请求信息

    ssize_t n= recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)& peer,&len);
    if(n<0){
      perror("recvfrom");
      continue;
    }
    
    buf[n]='\0';

    //根据请求计算响应结果,回显服务器不需要
 
    n=sendto(sock,buf,strlen(buf),0,(sockaddr*)& peer,len);
    //将收到的内容返回给服务器
    
    if(n<0){
      perror("sendto!");
      continue;
    }
   
    //打印一下客服端发来的内容
    printf("[%s:%d] buf:%s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf );
  }
  close(sock);//关闭文件描述符
  return 0;
}
