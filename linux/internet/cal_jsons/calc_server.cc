
#include<string>
#include"tcp_thread_server.hpp"
#include<jsoncpp/json/json.h>


//请求
//响应
//约定协议
//使用JSon 的方式进行序列化和反序列化
//{
//"nums":[10,20,30,40],  //Json中的[]表示数组,[]数字个数不限
//"op":"+",
//}
//
//{
//"result":30
//}
//
//如何解析Json 格式? //涉及到编译原理内容  
//此处可以借助第三方库，直接完成解析和操作jsoncpp
//josn::Value  用来表示一个 JSon 数据
//Json::Reader  把字符串转换成字符串
//Json::Writer 把Json::Value 转成字符串


/*
 * 
 */

int main(){
  TcpThreadServer server;
  server.Start("0.0.0.0",9090,[](const std::string& req,std::string *resp){
      //1.先将req进行反序列化
      Json::Reader reader;
      Json::Value  req_json;
      reader.parse(req,req_json);  //反序列化,第一个参数就是要转换的字符串
      //核心数据全都存储在req_json
      //第二个参数是一个输出型参数
      //2.根据反序列化的结果，进行结算
      Json::Value& nums=req_json["nums"];
      std::string op=req_json["op"].asString();  //操作符转换
      int result=0;
      //2.进行计算
      for(size_t i=0;i<nums.size();i++){
      if(op=="+"){
      result+=nums[(int)i].asInt();
      }else if(op=="-"){
      result-=nums[(int)i].asInt();
      }else if(op=="*"){
      result*=nums[(int)i].asInt();
      }else if(op=="/"){
      result /=nums[(int)i].asInt();
      }
      }

      //3.需要把结果再序列化会一个字符串
      Json::FastWriter writer; //需要用到Json的FastWriter对象
      Json::Value  resp_json;
      resp_json["result"]=result;
      *resp=writer.write(resp_json);//转换成字符串传回
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
