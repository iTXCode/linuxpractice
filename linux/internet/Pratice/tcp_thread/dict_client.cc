#include"tcp_client.hpp"

int main(int argc,char* argv[]){

  if(argc!=2){
    printf("Usage ./client [ip]\n");
    return 1;
  }
   
  TcpClient client;

  bool ret=client.Connect(argv[1],9090);

  if(!ret){
    printf("connect failed!\n");
    return 1;
  }

  while(true){
    printf("请输入你要查找的内容:");
    char req[1024*4]={0};
    fflush(stdout);
    scanf("%s",req);

    //把读到的信息发送给服务器
    client.Send(req);

    std::string resp;
    client.Recv(&resp);

    printf("resp:%s\n",resp.c_str());
  }
  
  return 0;
}
