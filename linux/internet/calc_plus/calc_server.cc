#include"tcp_thread_server.hpp"
#include<jsoncpp/json/json.h>
#include<string>

//请求
//响应
// 约定协议
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
      //2.进行计算
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


/*
序列化的方法
#include<sstream>

std::stringstream  ss(req);   //用req进行初始化
int num1=0'
int num2=0;
std::string op;
ss>>num1;   //cin重从键盘读取数据,而ss从stringstream中读取数据
ss>>num2;
ss>>op

 //2.进行计算
 int reet=0;
 if(op=="+"){
   ret=num1+num2;
 }else if(op=="-"){
   ret=num1-num2;
 }else if(op=="*"){
   ret=num1*num2;
 }else if(op=="/"){
   ret=num1/num2;
 }

 *resp=std::to_string(ret); //将计算结果反序列化成字符串
 
*/