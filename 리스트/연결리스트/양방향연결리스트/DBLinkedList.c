#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist) {

    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->prev = NULL;
    
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;

    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;

    plist->cur = NULL;
    plist->numOfData = 0;
}

//O(1)
void LInsert(List* plist, LData data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    plist->tail->prev->next = newNode;
    newNode->prev = plist->tail->prev;

    plist->tail->prev = newNode;
    newNode->next = plist->tail;

    (plist->numOfData)++;
}

//O(1)
int LFirst(List* plist, LData* pdata) {

    if (plist->head->next == plist->tail) return FALSE;

    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

//O(1)
int LNext(List* plist, LData* pdata) {

    if (plist->cur->next == plist->tail) return FALSE;

    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

//O(1)
LData LRemove(List* plist) {

    Node* rpos = plist->cur;
    LData rdata = plist->cur->data;

    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;

    plist->cur = plist->cur->prev;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist) {
    return plist->numOfData;
}