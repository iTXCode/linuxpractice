#include<iostream>
#include<malloc.h>
#include<memory.h>

template <class T>

class Heap{
  public:
    Heap(){
      _array=NULL;
    _size=0;
    }

    void Swap(T* a,T* b){
      T tmp=*a;
      *a=*b;
      *b=tmp;
    }
    

    void PrintHeap(const Heap<T>* heap){
      for(int i=0;i<heap->_size;i++){
        printf("%d ",heap->_array[i]);
      }
      printf("\n");
    }


    void AdjustDown(T* array,int size,int root){
     
      while(1){
        int left=2*root+1;
        int right=2*root+2;

        if(left>=size){
          return;
        }

        int min=left;
        if(right<size&&array[right]<array[left]){
          min=right;
        }

        if(array[root]<=array[min]){
          return;
        }

        Swap(array+root,array+min);
        root=min; 
      }

    }


    void CreateHeap(T* array,int size){
      for(int i=(size-2)/2;i>=0;i--){
        AdjustDown(array,size,i);
      }
    }



    void HeapInit(Heap <T>* heap,const T* array,int size){
      heap->_array=(T*)malloc(sizeof(T)*size);
      memcpy(heap->_array,array,sizeof(T)*size);
      heap->_size=size;
      CreateHeap(heap->_array,heap->_size);
    }


    void AdjustUp( T* array,int size,int child){
      while(child!=0){
        if(child>=size){
          return;
        }

        int root=(child-1)/2;
        if(array[root]<=array[child]){
          return; 
        }

        Swap(array+root,array+child);
        child=root;
      }
    }

    void HeapPush(Heap<T>* heap,T value){
      heap->_array[heap->_size++]=value;
      AdjustUp(heap->_array,heap->_size,heap->_size-1);
    }
    


    void HeapPop(Heap<T>* heap){
      Swap(heap->_array,heap->_array+(heap->_size-1));
      heap->_size--;
      AdjustDown(heap->_array,heap->_size,0);
    }

    bool  HeapFind(const Heap<T>* heap,T  value){
      for(int i=0;i<heap->_size;i++){
        if(value==heap->_array[i]){
          return true;
        }
      }
      return false;
    }


    void HeapModify(Heap<T>* heap,T value,T M_value){
      int index=0;
      for(int i=0;i<heap->_size;i++){
        if(value==heap->_array[i]){
          index=i;
        }
      }

      heap->_array[index]=M_value;
    }


  private:
    T* _array;
    int _size;
};

