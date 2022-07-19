#include <stdlib.h>
#include "CircleQueue.h"

void QueueInit(Queue* pq) {
    pq->front = 0;
    pq->rear = 0;
}

int QIsEmpty(Queue* pq) {
    return pq->front == pq->rear;
}

int GetNextPos(int pos) {

    if (pos == LEN-1) return 0;
    return pos+1;
}

void Enqueue(Queue* pq, Data data) {

    if (GetNextPos(pq->rear) == pq->front) return ;

    pq->rear = GetNextPos(pq->rear);
    pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue* pq) {

    if (QIsEmpty(pq)) exit(-1);

    pq->front = GetNextPos(pq->front);
    return pq->queArr[pq->front];
}

Data Peek(Queue* pq) {

    if (QIsEmpty(pq)) exit(-1);
    return pq->queArr[GetNextPos(pq->front)];
}