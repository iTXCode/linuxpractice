
#include"udp_client.hpp"
#include<iostream>
#include<stdlib.h>

int main(int argc,char *argv[]){
 if(argc!=3){
   printf("Usage ./dict_client [ip] [port]\n");
   return 1;
 }

 UdpClient client(argv[1],atoi(argv[2]));
 while(true){
   std::string word;
   std::cout<<"请输入您要查寻的单词:";
   std::cin>>word;
   if(!std::cin){
     std::cout<<"Good Bye"<<std::endl;
     break;
   }
   client.SendTo(word);

   std::string result;
   client.RecvFrom(&result);
   std::cout<<word<<"意思为:"<<result<<std::endl;
   
 }
 return 0;
}
