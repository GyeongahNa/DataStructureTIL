#include "HashTable.h"

void TBLInit(Table* pt, HashFunc* f) {

    for (int i=0; i<TBLLEN; i++) 
        ListInit(&(pt->tbl[i]));
    pt->hf = f;
}

void TBLInsert(Table* pt, Key key, Value val) {

    Value tmp;
    if (TBLSearch(pt, key, &tmp)) return ;

    int hv = pt->hf(key);
    Slot slot = {key, val};
    LInsert(&(pt->tbl[hv]), slot);
}

int TBLSearch(Table* pt, Key key, Value* val) {

    int hv = pt->hf(key);

    Slot slot;
    if (LFirst(&(pt->tbl[hv]), &slot)) {
        if (slot.key == key) {
            *val = slot.val;
            return TRUE;
        }
        while (LNext(&(pt->tbl[hv]), &slot)) {
            if (slot.key == key) {
                *val = slot.val;
                return TRUE;
            }
        }
    }
    return FALSE;
}

int TBLDelete(Table* pt, Key key, Value* val) {

    int hv = pt->hf(key);

    Slot slot;
    if (LFirst(&(pt->tbl[hv]), &slot)) {
        if (slot.key == key) {
            LRemove(&(pt->tbl[hv]));
            *val = slot.val;
            return TRUE;
        }
        while (LNext(&(pt->tbl[hv]), &slot)) {
            if (slot.key == key) {
                LRemove(&(pt->tbl[hv]));
                *val = slot.val;
                return TRUE;
            }
        }
    }
    return FALSE;
}