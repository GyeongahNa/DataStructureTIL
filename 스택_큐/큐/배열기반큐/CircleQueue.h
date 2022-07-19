#ifndef __CIRCLE_QUEUE_H__
#define __CIRCLE_QUEUE_H__

#define LEN 100

typedef int Data;

typedef struct _cQueue {
    Data queArr[LEN];
    int front;
    int rear;
} CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data Peek(Queue* pq);

#endif