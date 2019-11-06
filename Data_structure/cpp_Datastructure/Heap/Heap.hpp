#include<iostream>
#include<memory.h>


template <class T>

struct Heap{
  T* heap;
  int size;
};

template <class T>
class CHeap{
  public:
    CHeap(){
      _heap=NULL;
    }

    void Swap(T* a,T* b){
      int t=*a;
      *a=*b;
      *b=t;
    }

    void Heap_Adjust_Down(T *array,int size,int root){

      while(1){  
        int left=root*2+1;
        if(left>=size){
          return;
        }

        int right=root*2+2;
        int max=left;
        if(array[left]>array[right]){
          max=right;
        }
        if(array[root]>array[max]){
          return;
        }
        Swap(array+max,array+root); 
        root=max;
      }
    }
    void CreateHeap(int *array,int size){
        _heap->heap=(T*)malloc(sizeof(T)*size);
        memcpy(_heap,array,sizeof(T)*size);
        for(int i=(size-2)/2;i>=0;i--){
          Heap_Adjust_Down(_heap->heap,size,i);
        }
        _heap->size=size;

    }
  private:
   Heap<T>*  _heap;
};

