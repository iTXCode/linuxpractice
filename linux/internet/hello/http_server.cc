/*
 * 服务器不管用户端的请求是什么都响应hello
 */

/*
#include"tcp_thread_server.hpp"

void HttpProcess(const std::string& req,std::string* resp){
//不管用户输入的请求内容是什么，都返回hello world
  (void)req;  //不管请求内容直接转换成void* 类型
  std::string first_line="HTTP/1.1 200 OK\n";
  std::string body="<html><div>hello world!</div></html>";
  std::string header="Content-Type: text/html\nContent-Length:"+std::to_string(body.size())+"\n";
  *resp=first_line + header+"\n"+body;

}

int main(){
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,HttpProcess);

  return 0;
}
*/



#include"tcp_thread_server.hpp"

void HttpProcess(const std::string& req,std::string* resp){
//不管用户输入的请求内容是什么，都返回hello world
  (void)req;  //不管请求内容直接转换成void* 类型
  std::string first_line="HTTP/1.1 302 Found\n";

  std::string header="Location: http://www.sogou.com\n";
  *resp=first_line + header+"\n";

}

int main(){
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,HttpProcess);

  return 0;
}
