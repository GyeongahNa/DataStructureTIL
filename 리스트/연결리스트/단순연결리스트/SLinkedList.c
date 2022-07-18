#include <stdlib.h>
#include "SLinkedList.h"

void ListInit(List* plist) {
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->before = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

//O(1)
void LInsert(List* plist, LData data) {
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData)++;
}

//O(1)
int LFirst(List* plist, LData* pdata) {

    if (plist->head->next == NULL) return FALSE;
    plist->before = plist->head;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    return TRUE;
}

//O(1)
int LNext(List* plist, LData* pdata) {

    if (plist->cur->next == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}

//O(1)
LData LRemove(List* plist) {

    Node* rpos = plist->cur;
    LData rdata = plist->cur->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist) {
    return plist->numOfData;
}


