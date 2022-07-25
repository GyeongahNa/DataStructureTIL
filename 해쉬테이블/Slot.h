#ifndef __SLOT_H__
#define __SLOT_H__

typedef int Key;
typedef char* Value;

typedef struct _slot {
    Key key;
    Value val;
} Slot;

#endif