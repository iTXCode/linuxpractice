#pragma once 
#include<iostream>
#include<stdlib.h>
#include<assert.h>

template <class T>

struct SeqList{
  SeqList(int capacity){
    _array=(T*)malloc(sizeof(SeqList<T>)*capacity);
    _size=0;
    _capacity=capacity;
  }
  T* _array;
  int _size;//记录有效元素个数
  int _capacity;//记录整个顺序表
};

template <class T>

class List{
public:
  List()
  {
     _first=NULL;
  }

  ~List(){

  }
  void ListInit(List<T> *list,int num){
    assert(list!=NULL);
    list->_first=new SeqList<T>(num);
    //在类与对象衔接的时候,没有将list->_first指向
    //我们需要的顺序表,导致段错误
  }
  void PushFront(List<T> * list,const T value){
  assert(list!=NULL);
   
  //从前往后的搬移数据的话,前面的数据会将后面的数据覆盖
  //因此需要从后往前依次搬移数据
  for(int i=list->_first->_size-1;i>=0;i--){
    list->_first->_array[i+1]=list->_first->_array[i];
  }
  //将要插入的值赋给顺序表的首元素
  list->_first->_array[0]=value;
  list->_first->_size++;
  }

  void PushBack(List<T>* list,const T value){
    assert(list!=NULL);


    list->_first->_array[list->_first->_size]=value;
    list->_first->_size++;
  }

  //删除元素
  //尾删
  void PopBack(List<T>* list){
    assert(list!=NULL);
    list->_first->_size--;
  }

  //头删
  //算法思想
  //将第二个元素往前移动将第一个元素覆盖掉
  //按照此方法依次覆盖后面的元素,直到用最后一个元素
  //将倒数第二个元素覆盖为止
  void PopFront(List<T>* list){
    assert(list!=NULL);

    //依次将第二个元素往后的元素往前移动
    //特别注意:循环的边界
    for(int i=0;i<list->_first->_size-1;i++){
      list->_first->_array[i]=list->_first->_array[i+1];
    }
    list->_first->_size--;
  }

  //修改给定元素的值
  void ModifyList(List<T> *list,int i,const T value){
    assert(list!=NULL);
    if(i<0||i>=list->_first->_size){
      std::cout<<"要删除的元素位置下标不合法!"<<std::endl;
      return;
    }
   int num= FindList(list,value);
   if(num!=-1){
     list->_first->_array[num]=value;
   }
  }

  //统计顺序表中有效元素的个数
  int CountSize(List<T>* list){
    assert(list!=NULL);
    return list->_first->_size;
  }
 
  //查看顺序表的容量
  int CountCapacity(List<T>* list){
    assert(list!=NULL);

    return list->_first->_capacity; 
  }

  //查找第一个与给定元素值相等的元素,并返回其下标
  //未找到则返回-1
  int FindList(List<T>* list,const T value){
    assert(list!=NULL);
    //遍历数组查找指定的元素
    for(int i=0;i<list->_first->_size;i++){
      if(list->_first->_array[i]==value)
        return i;
    }
    return -1;
  }
  void PrintList(List<T>* list){
    assert(list!=NULL);
    
    //遍历整个顺序表,将顺序表打印出来
    for(int i=0;i<list->_first->_size;i++){
      std::cout<<list->_first->_array[i]<<" ";
    }
    std::cout<<std::endl;
  }

private:
  SeqList<T> *_first;
};
