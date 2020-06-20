#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(){
  int sock=socket(AF_INET,SOCK_DGRAM,0);
  if(sock<0){
    perror("socket!");
    return 1;
  }

  //准备工作
  sockaddr_in addr;
  addr.sin_family=AF_INET;
  addr.sin_port=htons(9090);
  addr.sin_addr.s_addr=inet_addr("0.0.0.0");
  int ret=bind(sock,(sockaddr*)& addr,sizeof(addr));
  if(ret<0){
    perror("bind!");
    return 1;
  }

  printf("server is OK!\n");

  while(true){
    sockaddr_in peer;
    char buf[1024]={0};
    socklen_t len=sizeof(peer);
    ssize_t n=recvfrom(sock,buf,sizeof(buf)-1,0,(sockaddr*)& peer,&len);
    
    if(n<0){
      perror("recvfrom!");
      continue;
    }
    buf[n]='\0';

    //根据请求计算响应,此处回显服务器
    
    //返回计算结果
    n=sendto(sock,buf,strlen(buf),0,(sockaddr*)&peer,len);

    if(n<0){
      perror("sendto!");
      continue;
    }

    printf("[%s:%d] res:%s\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port),buf);
  }
  close(sock);
  return 0;
}
