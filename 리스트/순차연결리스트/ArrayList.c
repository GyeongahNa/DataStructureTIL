#include <stdlib.h>
#include "ArrayList.h"

void ListInit(List* plist) {
    plist->curPosition = -1;
    plist->numOfData = 0;
}

//O(1)
void LInsert(List* plist, LData data) {
    
    if (plist->numOfData >= LEN) return ;
    plist->arr[(plist->numOfData)++] = data;
}

//O(1)
int LFirst(List* plist, LData* pdata) {

    if (plist->numOfData == 0) return FALSE;
    plist->curPosition = 0;
    *pdata = plist->arr[0];
    return TRUE;
}

//O(1)
int LNext(List* plist, LData* pdata) {

    if (plist->curPosition+1 >= plist->numOfData) return FALSE;
    *pdata = plist->arr[++(plist->curPosition)];
    return TRUE;
}

//O(n)
LData LRemove(List* plist) {

    int cur = plist->curPosition;
    int num = plist->numOfData;
    LData rdata = plist->arr[cur];

    for (int i=cur; i<num-1; i++) 
        plist->arr[i] = plist->arr[i+1];
    
    (plist->curPosition)--;
    (plist->numOfData)--;
    return rdata;
}

int LCount(List* plist) {
    return plist->numOfData;
}