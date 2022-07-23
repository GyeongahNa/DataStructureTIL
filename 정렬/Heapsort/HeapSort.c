#include <stdio.h>
#include "Heap.h"

int cmp(HData data1, HData data2) {

    if (data1 == data2) return 0;
    if (data1 < data2) return 1;
    return -1;
}

void HeapSort(int arr[], int n, PriorityCmp cmp) {

    Heap heap;
    HInit(&heap, cmp);

    for (int i=0; i<n; i++) HInsert(&heap, arr[i]);
    for (int i=0; i<n; i++) arr[i] = HDelete(&heap);
}

int main() {

    Heap heap;
    HInit(&heap, cmp);

    int arr[10] = {3, 10, 2, 5, 9, 7, 1, 6, 4, 8};
    HeapSort(arr, sizeof(arr)/sizeof(int), cmp);

    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}