#include <stdlib.h>
#include "ListStack.h"

void StackInit(Stack* pstack) {
    pstack->head = NULL;
}

int SIsEmpty(Stack* pstack) {
    return pstack->head == NULL;
}

void Push(Stack* pstack, Data data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = pstack->head;
    pstack->head = newNode;
}

Data Pop(Stack* pstack) {

    if (SIsEmpty(pstack)) exit(-1);

    Node* rpos = pstack->head;
    Data rdata = pstack->head->data;

    pstack->head = pstack->head->next;
    free(rpos);
    return rdata; 
}

Data Peek(Stack* pstack) {
    
    if (SIsEmpty(pstack)) exit(-1);
    return pstack->head->data;
}