#include<cstdio>
#include<cstring>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main(int argc,char* argv[]){

  int sock=socket(AF_INET,SOCK_DGRAM,0);

  if(sock<0){
    perror("socket!");
    return 1;
  }

  //客户端不需要绑定指定的固定的端口号
  //用来和服务器进行交流,系统会自动分配
  
  sockaddr_in server_addr;
  server_addr.sin_family=AF_INET;
  server_addr.sin_addr.s_addr=inet_addr(argv[1]);
  server_addr.sin_port=htons(9090);


  while(true){
  char buf[1024]={0};

  printf("请输入内容:");
  scanf("%s",buf);
  fflush(stdout);

  sendto(sock,buf,strlen(buf),0,(sockaddr*)& server_addr,sizeof(server_addr));

  char server_put[1024]={0};
  recvfrom(sock,server_put,strlen(server_put)-1,0,NULL,NULL);

  printf("server resp:%s\n",server_put);
  }

  return 0;
}
