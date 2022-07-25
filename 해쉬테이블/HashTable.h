#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "List/SLinkedList.h"
#include "Slot.h"

#define TBLLEN 100
#define TRUE 1
#define FALSE 0

typedef int HashFunc(Key key);

typedef struct _table {
    List tbl[TBLLEN];
    HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc* f);
void TBLInsert(Table* pt, Key key, Value val);
int TBLSearch(Table* pt, Key key, Value* val); //key에 해당하는 value를 찾아 val에 저장
int TBLDelete(Table* pt, Key key, Value* val); //key에 해당하는 slot을 찾아 삭제한 후 삭제한 값을 val에 저장

#endif