#include <stdlib.h>
#include "Heap.h"

void HInit(Heap* ph, PriorityCmp cmp) {
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
        if (ph->cmp(ph->arrHeap[parentIdx], data) >= 0) break;
        ph->arrHeap[idx] = ph->arrHeap[parentIdx];
        idx = parentIdx;
    }

    ph->arrHeap[idx] = data;
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
    if (ph->cmp(ph->arrHeap[leftIdx], ph->arrHeap[rightIdx]) >= 0) return leftIdx;
    return rightIdx;
}

HData HDelete(Heap* ph) {

    if (HIsEmpty(ph)) exit(-1);

    HData rdata = ph->arrHeap[1];
    HData data = ph->arrHeap[ph->numOfData];

    int idx = 1;
    int childIdx;
    while ((childIdx = GetHighPriorityChild(ph, idx))) {
        if (ph->cmp(data, ph->arrHeap[childIdx]) >= 0) break;
        ph->arrHeap[idx] = ph->arrHeap[childIdx];
        idx = childIdx;
    }
    ph->arrHeap[idx] = data;
    (ph->numOfData)--;
    return rdata;
}