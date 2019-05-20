//#include<stdio.h>
//#include<unistd.h>
//#include<fcntl.h>
//
//int main(){
//  //重定向:将打印到显示器上的内容输入到了文件中
//  //这种 操作依赖操作系统 的底层行为
//  close(1); //关闭了标准输出的文件描述符,不能正确的读写了
//  int fd=open("test.txt",O_WRONLY); //第二个参数决定了打开的方式
//  fprintf(stderr,"fd=%d\n",fd); //往文件中写
//  printf("新的输出:%d \n",stdout->_fileno);//stdout->_fileno(文件描述符)
//  //在test.txt中输出了结果
//  //fprintf(stdout,"新的输出:%d \n",stdout->_fileno);//等价于上一句
//  return 0;
//}


//#include<stdio.h>
//#include<unistd.h>
//#include<fcntl.h>
//#include<string.h>
//
//int main (  ){
// // printf("hehe\n");
//  fprintf(stdout,"haha\n");
//  write(1,"gege\n",strlen("gege\n")); //第一个参数文件描述符，stdout(file*)
// // fork();//加上fork出现两份hehe和haha 原因是write无缓冲区直接输出到屏幕上，
//  //而hehe与haha还在缓冲区中(虚拟地址)所以出现了两份
//  return 0;
//}
//



//c语言对文件的操作
#include <stdio.h>
#include <string.h>
int main()
{
 FILE *fp = fopen("myfile", "w");
 if(!fp){
 printf("fopen error!\n");
 }
 const char *msg = "hello bit!\n";
 int count = 5;
 while(count--){
 fwrite(msg, strlen(msg), 1, fp);
 }
 fclose(fp);
 return 0;
}

