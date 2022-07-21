#include <stdlib.h>
#include "Heap.h"

void HeapInit(Heap* ph, PriorityCmp cmp) {
    ph->numOfData = 0;
    ph->cmp = cmp;
}

int HIsEmpty(Heap* ph) {
    return ph->numOfData == 0;
}

int GetParentIdx(int idx) {
    return idx/2;
}

void HInsert(Heap* ph, HData data) {

    int idx = ph->numOfData+1;

    while (idx != 1) {
        int parentIdx = GetParentIdx(idx);
        if (ph->cmp(ph->heapArr[parentIdx], data) >= 0) break;
        ph->heapArr[idx] = ph->heapArr[parentIdx];
        idx = parentIdx;
    }
    ph->heapArr[idx] = data;
    (ph->numOfData)++;
}

int GetLeftChild(int idx) {
    return idx*2;
}

int GetRightChild(int idx) {
    return idx*2+1;
}

int GetHighPriorityChild(Heap* ph, int idx) {
    
    int leftIdx = GetLeftChild(idx);
    int rightIdx = GetRightChild(idx);
    if (leftIdx > ph->numOfData) return 0;
    if (leftIdx == ph->numOfData) return leftIdx;
    if (ph->cmp(ph->heapArr[leftIdx], ph->heapArr[rightIdx]) >= 0) return leftIdx;
    return rightIdx;
}

HData HDelete(Heap* ph) {

    if (HIsEmpty(ph)) exit(-1);

    HData rdata = ph->heapArr[1];
    HData data = ph->heapArr[ph->numOfData];

    int idx = 1;
    int childIdx;
    while ((childIdx = GetHighPriorityChild(ph, idx))) {
        if (ph->cmp(data, ph->heapArr[childIdx]) >= 0) break;
        ph->heapArr[idx] = ph->heapArr[childIdx];
        idx = childIdx;
    }
    ph->heapArr[idx] = data;
    (ph->numOfData)--;
    return rdata;
}