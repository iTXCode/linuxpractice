#include"seqlist.h"

static void CheckCapccity(SeqList *seqlist){
  //检查是否需要扩容
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(seqlist->_size<=seqlist->_capacity);
  //检查是否需要扩容
  if(seqlist->_size<seqlist->_capacity){
    return;
  }

  //走到这里就需要扩容了
  
  SDataType capacity=2*seqlist->_capacity;
  SDataType *array=(SDataType*)malloc(sizeof(SDataType)*capacity);
  //将老数据搬到新的空间中
  for(int i=0;i<seqlist->_size;i++){
    array[i]=seqlist->array[i];
  }

  free(seqlist->array);
  seqlist->array=array;
}

void SeqListInit(SeqList *seqlist, int capacity){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  seqlist->array=(SDataType*)malloc(sizeof(SDataType)*capacity);
  seqlist->_size=0;
  seqlist->_capacity=capacity;
}

void SeqListDestroy(SeqList *seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(seqlist->_size>0);
  seqlist->_size=0;
  seqlist->_capacity=0;
  free(seqlist->array);
}

void SeqListPushBack(SeqList *seqlist, SDataType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  CheckCapccity(seqlist);
  seqlist->array[seqlist->_size]=value;
  seqlist->_size++;
}


void SeqListPushFront(SeqList *seqlist,SDataType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  //往后顺序表中现有的数据
  CheckCapccity(seqlist);
  for(int i=seqlist->_size;i>=0;i--){
    seqlist->array[i]=seqlist->array[i-1];
  }
  seqlist->array[0]=value;
  seqlist->_size++;
}


void SeqListInsert(SeqList *seqlist,int pos,SDataType value){
  //从指定的位置插入某个元素
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&&pos<=seqlist->_size);
  CheckCapccity(seqlist);
  //从指定的位置开始往后移动数据
  for(int i=seqlist->_size-1;i>=pos;i--){
    seqlist->array[i+1]=seqlist->array[i];
  }
  seqlist->array[pos]=value;
  seqlist->_size++;
}


void SeqListPopBack(SeqList* seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  seqlist->_size--;
}

void SeqListPopFront(SeqList* seqlist){
  //头删
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  for(int i=0;i<seqlist->_size;i++){
    seqlist->array[i]=seqlist->array[i+1];
  }
  seqlist->_size--;
}

void SeqListErase(SeqList *seqlist,int pos){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&&pos<seqlist->_size);
  for(int i=pos;i<seqlist->_size;i++){
    seqlist->array[i]=seqlist->array[i+1];
  }
  seqlist->_size--;
}

void SeqListPrint(const SeqList *seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  for(int i=0;i<seqlist->_size;i++){
    printf("%d  ",seqlist->array[i]);
  }
  printf("\n");
}

void SeqListModify(SeqList *seqlist,int pos, SDataType value){
  //修改指定位置的值
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(pos>=0&&pos<seqlist->_size);
  seqlist->array[pos]=value;
}

int SeqListFind(const SeqList *seqlist,SDataType value){
  //查找指定位置的值找到返回位置下标,找不到返回-1
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  for(int i=0;i<seqlist->_size;i++){
    if(seqlist->array[i]==value){
      return i;
    }
  }
  return -1;
}

void  SeqListRemove(SeqList *seqlist,SDataType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  //找到并删除遇到的第一个value
  int pos=SeqListFind(seqlist,value);
  if(pos!=-1){
    SeqListErase(seqlist,pos);
  }
}

bool SeqListEmpty(const SeqList *seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  if(seqlist->_size==0){
    return true;
  }
  return false;
}

int SeqListSize(const SeqList *seqlist){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  return seqlist->_size;
}

void SeqListRemoveALl(SeqList* seqlist,SDataType value){
  assert(seqlist!=NULL);
  assert(seqlist->array!=NULL);
  assert(seqlist->_size>0);
  for(int i=0;i<seqlist->_size;i++){
    if(seqlist->array[i]==value){
      SeqListErase(seqlist,i);
    }
  }
}
