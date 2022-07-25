#include <stdio.h>
#include "Slot.h"
#include "HashTable.h"

int GetHashVal(Key key) {
    return key%100;
}

int main() {

    Table table;
    TBLInit(&table, GetHashVal);

    TBLInsert(&table, 20171003, "Lee");
    TBLInsert(&table, 20171004, "Kim");
    TBLInsert(&table, 20171013, "Na");
    TBLInsert(&table, 20171053, "Park");

    char* val;
    if (TBLSearch(&table, 20171003, &val)) printf("%s\n", val);
    if (TBLSearch(&table, 20171013, &val)) printf("%s\n", val);

    TBLDelete(&table, 20171003, &val);
    printf("%s\n", val);
    if (TBLSearch(&table, 20171003, &val)) printf("%s\n", val);
    else printf("없음\n");
}