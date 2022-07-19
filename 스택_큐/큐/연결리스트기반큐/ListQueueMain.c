#include <stdio.h>
#include "ListQueue.h"

int main() {

    Queue queue;
    QueueInit(&queue);

    int arr[5] = {1, 2, 3, 4, 5};
    for (int i=0; i<5; i++) Enqueue(&queue, arr[i]);

    while (!QIsEmpty(&queue))
        printf("%d ", Dequeue(&queue));
    return 0;
}