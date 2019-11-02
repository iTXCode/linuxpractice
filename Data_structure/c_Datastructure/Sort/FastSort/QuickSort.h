#include<stdio.h>

//快速排序

void Swap(int *a,int*b){
  int t=*a;
  *a=*b;
  *b=t;
}

//parition用三种方式实现
int  Parition_1(int array[],int left,int right){
  int begin=left;
  int end=right;//不能是right-1
  //基(基准值)在右,左先走
  //基在左，右先走
  while(begin<end){
    while(begin<end&&array[begin]<=array[right]){//=不能丢,可能造成死循环
      begin++;
    }
    //走到这里的时候,说明左边卡住了
    //左边有值大于array[right]了
    while(begin<end&&array[end]>=array[right]){
      end--;
    }
    //走到这里的时候右边也卡住了
    //右边有值大于基准值了
    Swap(array+begin,array+end);
  }
  return begin;
}



//区间被分成小，大，基准值

void _QuickSort(int array[],int left,int right){
  //终止条件 size==0||size==1
  //left==right  区间内还剩一个数
  //left>right 区间内没有数
  if(left==right){
    return;
  }
  if(left>right){
    return;
  }

  int div;//用于记录选出的基准值
  //比基准值大的要放到基准值左侧
  //比基准值小的放到基准值右侧
  div=Parition_1(array,left,right);
  _QuickSort(array,left,div-1);
  //递归解决基准值左侧的数
  _QuickSort(array,div+1,right);
  //递归解决基准值右侧的数
}


void QuickSort(int *array,int size){
  _QuickSort(array,0,size-1);
}

void PrintSort(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}
void Test(){
  int array[]={1,9,3,4,2,7,6,8,0,5};
  int size=sizeof(array)/sizeof(array[0]);
  PrintSort(array,size);
  QuickSort(array,size);
  PrintSort(array,size);
}
