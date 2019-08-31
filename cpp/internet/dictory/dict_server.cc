//创建一个中英文翻译的服务器
//用户输入一个 英文 单词,返回一个翻译出来的中文结果
//跳表
#include"udp_server.hpp" 
//通过哈希表的方式来实现,没有规定必须通过哈希表的方式实现
#include<unordered_map>

//1.啥样的对象才能放到 vector
//a.能拷贝的对象
//b.支持移动语义
//2.啥样的对象能放到list里面(和vector相同)
//3.啥样的对象能放到deque 里面(和vector相同)
//4.啥样的对象能放到std::array 里面(和vector相同)
//5.std::set 
//a.能拷贝
//b.能够比较<
//6.std::map: key a.能拷贝   b.能比较
//value 能拷贝就行
//7.std::unordered_map  key a.能拷贝  b.能比较相等  c.能哈希
//value  能拷贝就行
//&& 右值引用 
//转移构造函数
//体现了C++ 中的"移动语义"
int main(){
  std::unordered_map<std::string,std::string>  dict; 
  dict.insert(std::make_pair("hello","你好"));
  dict.insert(std::make_pair("bit","比特"));
  dict.insert(std::make_pair("world","世界"));
      
  UdpServer server;
  //lambda 表达式的[] 中可以写东西
  //把 lambda 外部的变量 "捕捉" 到lambda 表达式里面
  //捕获可以按值捕获,也可以按引用捕获
  server.Start("0.0.0.0",9090,[&dict](const std::string& req,
        std::string *resp){
      //*resp=req;
      auto it=dict.find(req);
      if(it==dict.end()){
      *resp="未查到结果";
      }else{
      *resp=it->second;
      }
      }); //启动服务器
  return 0;
}

