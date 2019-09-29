#pragma once
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int value;
      struct Node *next;

} Node;

// 头删 + 尾插
typedef struct Queue {
  Node *front;    // 链表的第一个结点
  Node *rear;     // 链表的最后一个结点
  int size;     // 数据个数
} Queue;

// 初始化
void QueueInit(Queue *queue) {
  queue->front = NULL;
  queue->rear = NULL;
  queue->size = 0;
}
// 销毁
void QueueDestroy(Queue *queue) {
  Node *node, *next;
  for (node = queue->front; node != NULL; node = next) {
    next = node->next;
    free(node);
  }

  queue->front = queue->rear = NULL;
  queue->size = 0;
}

// Push ，队尾插入，即链表的尾插
void QueuePush(Queue *queue, int val) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->value = val;
  node->next = NULL;
  queue->size++;

  if (queue->rear != NULL) {
    queue->rear->next = node;
    queue->rear = node;
  }
  else {
    queue->front = queue->rear = node;
  }
}

// Pop， 队首出列，即链表的头删
void QueuePop(Queue *queue) {
  assert(queue->size > 0);
  queue->size--;
}







