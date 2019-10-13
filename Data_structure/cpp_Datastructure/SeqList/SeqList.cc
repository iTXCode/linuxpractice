#include"SeqList.hpp"


void TestSeqList(){
  List<int> list;
  list.ListInit(&list,10);
  list.PushFront(&list,1);
  list.PushBack(&list,2);
  list.PrintList(&list);
}
int main(){
  TestSeqList();
  return 0;
}
