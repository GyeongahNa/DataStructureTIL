#include <stdlib.h>
#include "ArrayStack.h"

void StackInit(Stack* pstack) {
    pstack->topIdx = -1;
}

int SIsEmpty(Stack* pstack) {
    return pstack->topIdx == -1;
}

void Push(Stack* pstack, Data data) {

    if (pstack->topIdx >= LEN-1) return ;
    pstack->stackArr[++(pstack->topIdx)] = data;
}

Data Pop(Stack* pstack) {

    if (SIsEmpty(pstack)) exit(-1);

    Data rdata = pstack->stackArr[pstack->topIdx];
    (pstack->topIdx)--;
    return rdata;
}

Data Peek(Stack* pstack) {

    if (SIsEmpty(pstack)) exit(-1);
    return pstack->stackArr[pstack->topIdx];
}