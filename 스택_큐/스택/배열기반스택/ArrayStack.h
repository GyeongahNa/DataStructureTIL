#ifndef __ARRAY_STACK_H__
#define __ARRAY_STACK_H__

#define LEN 100

typedef int Data; 

typedef struct _arrayStack {
    Data stackArr[LEN];
    int topIdx;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);

#endif