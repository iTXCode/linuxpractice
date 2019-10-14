#include"SeqList.hpp"


void TestSeqList(){
  List<int> list;
  list.ListInit(&list,2);
  list.PushFront(&list,1);
  list.PushBack(&list,2);
  list.InsertSeqList(&list,1,3);
  list.PrintList(&list);
  list.PushBack(&list,4);
  list.PrintList(&list);
  list.PopListPosition(&list,1);
  list.PrintList(&list);
  list.PopBack(&list);
  list.PrintList(&list);
  list.PopFront(&list);
  list.PrintList(&list);
  
}
int main(){
  TestSeqList();
  return 0;
}
