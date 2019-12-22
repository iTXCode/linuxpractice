#include"tcp_client.hpp"

int main(int argc,char* argv[]){
  if(argc!=2){
    printf("Usage ./client [ip]\n");
    return 1;
  }

  TcpClient client;
  bool ret=client.Connect(argv[1],9090);
  if(!ret){
    printf("Connect  failed!\n");
    return 1;
  }

  //连接已经建立了
  while(true){
    printf("请输入一个需要查询的单词:");
    fflush(stdout);
    char req[1024]={0};
    scanf("%s",req);
    client.Send(req);

    std::string resp;
    client.Recv(&resp);
    printf("resp:%s\n",resp.c_str());
    
  }

  return 0;
}
