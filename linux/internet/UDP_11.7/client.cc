//实现UDP版本的客户端

#include<stdio.h>
#include<sys/socket.h>  //socket所用的头文件
#include<netinet/in.h>  //socketaddr_in 结构体的头文件
#include<arpa/inet.h>   //inet.addr的头文件
#include<cstring>
#include<unistd.h>


//./client [ip]
//客户端以在链接服务器的时候指明服务器的IP地址
//通过命令行参数的方式指定服务器的IP地址
//eg: ./client 192.168.221.134
//这个命令中下标为1 的参数即为指定的IP地址
int main(int argc,char *argv[]){//让用户以命令行
  //的形式输入服务器的ip
     
  //1.先创建一个socket 文件
  int sock=socket(AF_INET,SOCK_DGRAM,0);
  //参数表述:
  //1:AF_INET 是一个宏,表示IPV4协议
  //2:SOCK_DGRAM 表示使用UDP协议
  //3.一般不用写成0
  if(sock<0){
    perror("socket");
    return 1;
  }

  //客户端一般不需要bind
  //bind  意味着和某个具体的端口号关联在一起
  //如果没有bind，操作系统会随机分配一个端口号
  //如果是服务器程序不去bind ，就会导致每次启
  //动服务器时服务器的端口都会发生变化
  //客户端就没法连接了
  //如果客户端bind的话,可能会出现问题
  //通常情况下，一个端口号只能被一个进程bind
  //如果客户端bind一个端口号其他客户端也可能bind
  //同一个端口号
  //就会出错
  //客户端最好还是让操作系统随机分配更科学
  
  //2.准备好服务器的sockaddr_in 结构
  sockaddr_in  server_addr;
  server_addr.sin_family=AF_INET;
  server_addr.sin_addr.s_addr=inet_addr(argv[1]);
  //inet_addr 获取服务器的ip
  server_addr.sin_port=htons(9090);
   
  //3.客户端直接发送数据即可
  while(true){
    char buf[1024]={0};
    printf("请输入一段内容:");
    fflush(stdout);
    scanf("%s",buf);
    sendto(sock,buf,strlen(buf),0,
        (sockaddr*)&server_addr,sizeof(server_addr));
    //从服务器接受一下返回结果
    char buf_output[1024]={0};
    //后两个参数填NULL 表示不关注对端的地址
    recvfrom(sock,buf_output,sizeof(buf_output)-1,0,
          NULL,NULL);
    printf("server resp:%s\n",buf_output);
  }
  return 0;
}

//2:00