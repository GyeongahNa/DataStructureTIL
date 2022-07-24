#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* next;
} Node;

typedef struct _listQueue {
    Node* front;
    Node* rear;
} ListQueue;

typedef ListQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data Peek(Queue* pq);

#endif