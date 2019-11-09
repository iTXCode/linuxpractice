#include<iostream>
#include<memory.h>
#include<malloc.h>


template <class T>

struct Heap{
  Heap(){
    _array=NULL;
    _size=0;
  }
  T* _array;
  int _size;
};


template <class T>
class ReHeap{
  public:
    ReHeap(){
      _heap=NULL;
    }
  
    void HeapInit(ReHeap<T> *heap,Heap<T> Heap,const T* array,int size){
      heap->_heap=&Heap;
      heap->_heap->_array= (T*)malloc(sizeof(T)*size);
      memcpy(heap->_heap->_array,array,sizeof(T)*size);
      heap->_heap->_size=size;
      CreateHeap(heap->_heap->_array,heap->_heap->_size);
    }

    void PrintHeap(const T* array,int size){
     if(array==NULL){
        return;
      }
      for(int i=0;i<size;i++){
       printf("%d ",array[i]); 
      }
      printf("\n");
    }
  

    void Swap(T *a,T *b){
      T tmp=*a;
      *a=*b;
      *b=tmp;
    }

    //向下调整

    void AdjustDown(T* array,int size,int root){
      while(1){
        int left=2*root+1;
        int right=2*root+2;

        if(left>=size){
          //切记此处的left有可能等于size-1
          //若条件写成size-1会导致最后一个元素不会被调整
          return;
        }
        int min=left;
        //找出左右下标最小的那个和根结点值比较大小

        if(right<=size-1&&array[right]<array[left]){
          min=right; //剑小堆
        }

        if(array[root]<=array[min]){
          return;
        }
        Swap(array+root,array+min);
        root=min; 
      }

    }
    //建堆
    void CreateHeap(T* array,int size){
      if(array==NULL){
        return;
      }
      for(int i=(size-2)/2;i>=0;i--){
        AdjustDown(array,size,i);
      }
    }

    Heap<T>* getheap(){
      return _heap;
    }


    //往上调整
    void AdjustUp(T* array,int size,int child){
  
      while(child!=0)
      {
        if(child>size){
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

    void HeapPush(ReHeap<T>& heap,const T value){ 
     heap._heap->_array[heap._heap->_size++]=value;
  
     AdjustUp(heap._heap->_array,heap._heap->_size,heap._heap->_size-1); 
    }
  private:
    Heap<T>* _heap;
};
