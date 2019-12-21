#include"tcp_client.hpp"

int main(int argc,char *argv[]){
  if(argc!=2){
    printf("Usage ./dict_client [ip]\n");
    return 1;
    //如果用户输入有误的话,用于提示用户正确的输入方式
  }
  TcpClient  client;
  bool ret= client.Connect(argv[1],9090);
  if(!ret){
    printf("connect failed!\n");
    return 1;
  }
    while(true){
    //从标准输入读数据
    printf("请输入一个要查询的单词:");
    fflush(stdout);   
    //更改所有匹配项  按照字符串匹配的方式实现
    char req[1024]={0};
    scanf("%s",req);
    //把读到的数据发送给服务器
    client.Send(req);
    std::string resp;
    //读取服务器的响应结果
    client.Recv(&resp);
    //把响应结果显示到标准输出上
    printf("resp: %s\n",resp.c_str());
  }  
    return 0;
}

/*
c++黑点
1.编译慢
2.模板编译错误不友好
3.指针太难用
4.异常机制太简陋
5.新标准加的东西是什么看不懂
*/


/*
python的黑点
1.游标卡尺
2.Python一时爽,重构火葬场
*/

//当有多个客户端连接到服务器的时候,只有最先连接
//的客户端才能够与服务器进行交互