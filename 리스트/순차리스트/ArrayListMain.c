#include <stdio.h>
#include "ArrayList.h"

int main() {

    List list;
    ListInit(&list);

    //데이터 삽입
    int arr[5] = {1, 5, 3, 9, 10};
    for (int i=0; i<5; i++) LInsert(&list, arr[i]);

    //데이터 조회
    int data;
    if (LFirst(&list, &data)) {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
        printf("\n");
    }

    //3의 배수 원소 삭제
    if (LFirst(&list, &data)) {
        if (data%3 == 0) LRemove(&list);
        while (LNext(&list, &data)) 
            if (data%3 == 0) LRemove(&list);
    }

    //데이터 조회
    printf("남은데이터수: %d\n", LCount(&list));
    if (LFirst(&list, &data)) {
        printf("%d ", data);
        while (LNext(&list, &data))
            printf("%d ", data);
        printf("\n");
    }

    return 0;
}