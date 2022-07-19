#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

typedef int Data;

typedef struct _node {
    Data data;
    struct _node* next;
} Node;

typedef struct _listStack {
    Node* head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void Push(Stack* pstack, Data data);
Data Pop(Stack* pstack);
Data Peek(Stack* pstack);

#endif