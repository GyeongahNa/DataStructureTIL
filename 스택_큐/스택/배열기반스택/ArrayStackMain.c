#include <stdio.h>
#include "ArrayStack.h"

int main() {

    Stack stack;
    StackInit(&stack);

    int arr[5] = {1, 2, 3, 4, 5};
    for (int i=0; i<5; i++) Push(&stack, arr[i]);

    while (!SIsEmpty(&stack)) 
        printf("%d ", Pop(&stack));
    return 0;
}