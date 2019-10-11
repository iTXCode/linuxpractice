#pragma once
//#ifndef MYSHM_H
//#define MYSHM_H
#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>

static int CreateShm(){
  //1.static修饰全局变量:改变变量的作用域
  //2.修饰函数改变作用域
  //3.修饰局部变量:修改生命周期
  //4.C++中修饰类中的变量，使得变量变成类的属性
  //5.修饰成员函数,变成类的方法
  //shmget：shared memory get(获取)
  key_t key=ftok(".",0x2);
  //"."确实存在的路径
 if(key==-1){
   perror("ftok");
   return 1;

 }
 printf("key=%d\n",key);
 int ret=shmget(key,1024,IPC_CREAT |0666);
     //权限0666
     //IPC_EXCL可有可无
  if(ret<0){
    perror("shmget");
    return 1;
  }
  printf("ret=%d\n",ret);
  return ret;
}
