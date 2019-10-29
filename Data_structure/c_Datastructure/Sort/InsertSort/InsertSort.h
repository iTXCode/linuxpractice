#include<stdio.h>


void PrintArray(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}

//直接插入排序
//时间复杂度:O(N^2)
//最好时间复杂度   平均            最差
//O(1)(天生有序)   O(N^2)            O(N^2)(完全逆序)
//空间复杂度:O(1)
//稳定性:稳定
void InsertSort(int array[],int size){
  
  for(int i=1;i<size;i++){
    //要为array[i]找到位置
    int k=array[i];
    int j;
    for( j=i-1;j>=0;j--){
      if(array[j]<=k){
        break;
      }else{
        array[j+1]=array[j];
      }

    }
    array[j+1]=k;
  }
}

//排逆序的情况
void InsertSortR(int array[],int size){
  
  for(int i=1;i<size;i++){
    //要为array[i]找到位置
    int k=array[i];
    int j;
    for( j=i-1;j>=0;j--){
      if(array[j]>=k){
        break;
      }else{
        array[j+1]=array[j];
      }

    }
    array[j+1]=k;
  }
}

//插入排序
//二分查找位置


//希尔排序
//时间复杂度:
//最好时间复杂度    平均      最坏
//
//空间复杂度:

void InsertSortWithGap(int array[],int size,int gap){
  for(int i=gap;i<size;i++){
    int k=array[i];
    int j;
    for(j=i-gap;j>=0;j-=gap){
      if(array[j]<=k){
        break;
      }else{
        array[j+gap]=array[j];
      }
    }
    array[j+gap]=k;
  }
}

void ShellSort(int array[],int size){
  int gap=size;
  while(1){
    gap=gap/3+1;
    InsertSortWithGap(array,size,gap);
    if(gap==1){
      break;
    }
  }
}
void TestSort(){
  int array[]={2,1,4,3,6,5,7,9,8,0};
  int size=sizeof array/sizeof(int);
  InsertSort(array,size);
  PrintArray(array,size);
  InsertSortR(array,size);
  PrintArray(array,size);
  ShellSort(array,size);
  PrintArray(array,size);
}
