#include"queue.h"


int main(){
  Queue queue;
  QueueInit(&queue);
  QueuePush(&queue,1);
  QueuePush(&queue,2);
  QueuePush(&queue,3);
  QueuePush(&queue,4);
  QueuePush(&queue,5);
  PrintQueue(&queue);
  QueuePop(&queue);
  QueuePop(&queue);
  PrintQueue(&queue);
  return 0;
}
