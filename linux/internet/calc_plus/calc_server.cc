#include"tcp_thread_server.hpp"
#include<jsoncpp/json/json.h>
#include<string>

//请求
//响应
//
//使用JSon 的方式进行序列化和反序列化
//{
//"num1":10,
//"num2":20,
//"op":"+",
//}
//
//{
//"result":30
//}
//
//如何解析Json 格式? 
//借助第三方库，直接完成解析和操作
//josn::Value  用来表示一个 JSon 数据
//Json::Reader  把字符串转换成字符串

int main(){
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,[](const std::string& req,std::string *resp){
      //1.先将req进行反序列化
      Json::Reader reader;
      Json::Value  req_json;
      reader.parse(req,req_json);
      //第二个参数是一个输出型参数
      //根据反序列化的结果，进行结算
      int num1=req_json["num1"].asInt();
      int num2=req_json["num2"].asInt();
      std::string op=req_json["op"].asString();
      int result=0;
      if(op=="+"){
      result=num1+num2;
      }else if(op=="-"){
      result=num1-num2;
      }else if(op=="*"){
      result=num1*num2;
      }else if(op=="/"){
      result=num1/num2;
      }
      //3.需要把结果再序列化会一个字符串
      Json::FastWriter writer;
      Json::Value  resp_json;
      resp_json["result"]=result;
      *resp=writer.write(resp_json);
      });
  return 0;
}
