#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

//写一个用于切分字符串的函数Split
//input 表示带切分命令
//output 表示切分结果(字符串数组)
//返回值表示 output 中包含了几个有效元素
int Split(char input[],char* output[] ){
  //借助strtok来实现这个功能
  char* p =strtok(input," ");
  int i=0;
  while(p!=NULL){
    output[i]=p;
    ++i;
    p=strtok(NULL," ");
  }
  output[i]=NULL; //这个操作是很容易遗忘的
  return i;
}

void CreateProcess(char* argv[],int n){
  (void) n;
  //1.创建子进程
  pid_t ret=fork();
  if(ret>0){
    //父进程逻辑
    wait(NULL);
    //暂时这样写,正常的话一个shell是应该知道子进程的退出码的
  }else if(ret==0){
    //child 
    //子进程进行程序替换


    ret=execvp(argv[0],argv);  
    //if条件可以省略,如果exec成功了
    //是肯定不会执行到这个代码的
    perror("exec");
    exit(0); 
  }else{
    //子进程创建错误
    perror("fork");
  }
  //2.父进程进行进程等待,子进程进行程序替换
}

/*strtok 执行过程会破坏原始的字符串
 * 内部会保存上次的切分结果 
 * strtok 必须循环调用,并且第一次的参数和后续的参数不一样
 * 返回值是一个指针
 * */
int main(){
  while(1){
    //1.打印提示符
    printf("[myshell@iTXCode~]#");
    fflush(stdout);
    //2.用户输入一个指令
    char command[1024]={0};//缓冲区,用于存储用户指令
   //scanf("%s",command);
   //scanf 遇到空格就换行,所以不适用与此处
   gets(command);//gets 可以一次读入一行数据

   //3.解析指令,把要执行那个程序识别出来
   //那些是命令行参数识别出来(字符串切分)
   //strtok 函数功能:字符串切分
   //切分结果应该是一个字符串数组
   char* argv[1024];
   int n=Split(command,argv); 
   
   //4.创建子进程并且进行程序替换
   CreateProcess(argv,n);
   }
  return  0;
}

//1.打印一个提示符,并且让用户输入一个指令
//2.解析输入指令,找到对应的可执行程序
//3.创建子进程,子进程程序替换，来加载可执行程序
//4.父进程进行进程等待,等待子进程结束
//5.子进程结束,父进程从wait中返回，循环执行1


/*C++标准库的做法
 * #include<sstream>
 * 基于boost 的方案是比较科学的方案
 * boost algorithm/string.hpp
 * boost::split 
 * */


/*【规定】
 * 一个函数的输入参数用const&
 * 一个函数的输出参数用*
 * 一个函数的输入输出参数用&
 * */


/*myshell的改进
 * 1.自动获取到用户名,主机名，当前路径
 * 2.需要支持cd 命令(cd 修改的是子进程的路径,对父进程没有影响)
 * 需要让父进程直接支持cd(而不是创建子进程/程序替换)
 * 内建命令
 * 3.支持定义别名(需要程序中维护一个键值对数据结构)
 * 4.支持管道
 * 5.支持重定向
 * */
