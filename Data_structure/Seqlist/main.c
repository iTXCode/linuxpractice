#include"seqlist.h"

//void TestSeqList(){
//  SeqList seqlist;
//  SeqListInit(&seqlist,100);
//  SeqListPushFront(&seqlist,1);
//  SeqListPushBack(&seqlist,2);
//  SeqListPushBack(&seqlist,4);
//  SeqListPushBack(&seqlist,89);
//
//  SeqListPushBack(&seqlist,9);
// 
//  SeqListPushBack(&seqlist,56);
//  SeqListPushBack(&seqlist,67);
//  
//  SeqListInsert(&seqlist,2,3);
//  //1 2 3 4 89 9 56 67  
//  SeqListPrint(&seqlist);
//  SeqListPopFront(&seqlist);
//  // 2 3 4 89 9 56 67
//  SeqListPopBack(&seqlist);
//  // 2 3 4 89 9 56 
//  SeqListPrint(&seqlist);
//
//  SeqListEmpty();
//}
//


void  TestSeqList(){

  SeqList seqlist;
  SeqListInit(&seqlist,100);
  SeqListPushBack(&seqlist,1);
  SeqListPushFront(&seqlist,11);
  SeqListPushBack(&seqlist,2);
  SeqListPushFront(&seqlist,12);
  SeqListPushBack(&seqlist,3);
  SeqListPushFront(&seqlist,13);
  SeqListInsert(&seqlist,4,100);
  SeqListPopBack(&seqlist);
  SeqListPopFront(&seqlist);
  SeqListErase(&seqlist, 3);
  SeqListPrint(&seqlist);
  SeqListDestroy(&seqlist);
}
int main(){
  TestSeqList();
  return 0;
}
