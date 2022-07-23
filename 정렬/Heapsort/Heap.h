#ifndef __HEAP_H__
#define __HEAP_H__

#define LEN 100

typedef int HData;
typedef int (*PriorityCmp)(HData data1, HData data2);

typedef struct _heap {
    HData arrHeap[LEN];
    int numOfData;
    PriorityCmp cmp;
} Heap;

void HInit(Heap* ph, PriorityCmp cmp);
int HIsEmpty(Heap* ph);
void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);

#endif