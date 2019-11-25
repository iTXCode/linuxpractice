#include"queue.hpp"


void TestQueue(){
    Queue<int> queue;
    queue.QueuePush(&queue,1);
    queue.QueuePush(&queue,2);
    queue.QueuePush(&queue,3);
    std::cout<<queue.Size()<<std::endl;
    bool empty=queue.EmptyQueue(&queue);
    std::cout<<"队列是否为空:"<<empty<<std::endl;
    queue.PrintQueue(&queue);
    queue.QueuePop(&queue);
    queue.PrintQueue(&queue);
    queue.QueuePop(&queue);
    queue.PrintQueue(&queue);
    queue.QueuePop(&queue);
    queue.PrintQueue(&queue);
    queue.QueuePush(&queue,1);
    queue.QueuePush(&queue,2);
    queue.QueuePush(&queue,3);
    queue.PrintQueue(&queue);
    queue.DestoryQueue(&queue);
    queue.PrintQueue(&queue);
}

int main(){
    TestQueue();
    return 0;
}