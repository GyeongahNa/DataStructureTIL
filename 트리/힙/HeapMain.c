#include <stdio.h>
#include "Heap.h"

int cmp(HData data1, HData data2) {

    if (data1 == data2) return 0;
    if (data1 < data2) return 1;
    return -1;
}

int main() {

    Heap heap;
    HeapInit(&heap, cmp);

    int arr[10] = {5, 3, 1, 9, 10, 4, 11, 100, 20, 17};
    for (int i=0; i<10; i++) HInsert(&heap, arr[i]);

    while (!HIsEmpty(&heap)) printf("%d ", HDelete(&heap));
    return 0;
}