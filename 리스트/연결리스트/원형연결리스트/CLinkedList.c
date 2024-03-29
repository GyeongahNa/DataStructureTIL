#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List* plist) {
    plist->tail = NULL;
    plist->before = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

//O(1)
void LInsert(List* plist, LData data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    if (plist->tail == NULL) {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}

//O(1)
int LFirst(List* plist, LData* pdata) {

    if (plist->tail == NULL) return FALSE;
    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    *pdata = plist->cur->data;
    return TRUE;
} 

//O(1)
int LNext(List* plist, LData* pdata) {

    if (plist->tail == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}


//O(1)
LData LRemove(List* plist) {

    Node* rpos = plist->cur;
    LData rdata = plist->cur->data;

    if (rpos == plist->tail) {
        if (plist->tail == plist->tail->next) plist->tail = NULL;
        else plist->tail = plist->before;
    }

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist) {
    return plist->numOfData;
}
