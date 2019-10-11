//函数名相同,但是函数签名不同
//函数签名:参数列表+cv限定符(const,colatile)
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>
#include<string.h>

/*

c++ 标准库的做法
#include<sstream>

基于 boost 的方案是比较科学的方案
boost algotithm/string.hpp
boost::split

*/

//input 表示待切分命令
//output 表示切分结果(字符串数组)
//返回值表示 output 中包含了几个有效元素
int Split(char  input[], char *output[]){
	//借助 strtok 来实现
	char *p = strtok(input, " ");
	//返回值指向第一个 l 的指针
	int i = 0;
	while (p != NULL){
		//printf("%s\n",p);
		output[i] = p;
		++i;
		p = strtok(NULL, " ");
		//第二次返回值指向 - 的指针
		//第三次返回值指向/的指针
		//第四次返回值为NULL
	}
  output[i]=NULL;
  //这个操作是很容易被遗忘的
	return i;
}

void CreateProcess(char *argv[],int n){
    (void) n;
    //1.创建子进程
    pid_t ret=fork();
    //2.父进程进行进程等待,子进程进行程序替换
    if(ret>0){
        //father
        wait(NULL);
    }else if(ret==0){
        //child
        ret=execvp(argv[0],argv);
        if(ret<0){
            perror("exec");
            exit(0);
        }
        //此处的if条件可以省略,如果exec成功了,
        //程序肯定执行不到这里
    }else{
        perror("fork");
    }
}

int main(){
	while (1){
		//1.打印提示符
		printf("[myshell@localhot ~]$");
		fflush(stdout);
		//2.让用户输入指令
		char command[1024] = { 0 };
		//scanf("%s",command);
		//scanf中遇到空格打印一行命令的时候就会出错
		//用gets，一个参数，一次读入一行数据
		gets(command);
		//TODO测试下 scanf 能否读入一行数据
		//printf("%s\n", command);
		//3.解析指令,把我们要执行那个程序识别出来,
		//那些是命令行参数识别出来(字符串切分)
		//切分结果应该是一个字符串数组
		char *argv[1024] = { 0 };
		int n = Split(command,argv);

		//4.创建子进程并且进行程序替换
		CreateProcess(argv,n);
	}
	return 0;
}
