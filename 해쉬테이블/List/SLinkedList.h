#ifndef __S_LINKED_LIST_H__
#define __S_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

#include "../Slot.h"

typedef Slot LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _sLinkedList {
    Node* head;
    Node* before;
    Node* cur;
    int numOfData;
} SLinkedList;

typedef SLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);

#endif