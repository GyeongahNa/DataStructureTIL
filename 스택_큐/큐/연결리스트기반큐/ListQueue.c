#include <stdlib.h>
#include "ListQueue.h"

void QueueInit(Queue* pq) {

    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue* pq) {
    return pq->front == NULL;
}

void Enqueue(Queue* pq, Data data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (QIsEmpty(pq)) {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue* pq) {

    if (QIsEmpty(pq)) exit(-1);

    Node* rpos = pq->front;
    Data rdata =pq->front->data;

    pq->front = pq->front->next;
    free(rpos);
    return rdata;
}

Data Peek(Queue* pq) {

    if (QIsEmpty(pq)) exit(-1);
    return pq->front->data;
}