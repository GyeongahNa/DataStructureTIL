#include <stdio.h>
#include "ListQueue.h"

#define BUCKETLEN 10

//LSD(Least Significant Digit)
//O(n), stable, not in-place
void RadixSort(int arr[], int n, int maxLen) {

    int p = 1;
    Queue bucket[BUCKETLEN];
    for (int i=0; i<BUCKETLEN; i++) QueueInit(&bucket[i]);

    for (int i=0; i<maxLen; i++) {
        for (int j=0; j<n; j++)
            Enqueue(&(bucket[arr[j]/p%10]), arr[j]);
        int idx = 0;
        for (int j=0; j<BUCKETLEN; j++) {
            while (!QIsEmpty(&bucket[j]))
                arr[idx++] = Dequeue(&bucket[j]);
        }
        p *= 10;
    }
}

int main() {

    int arr[10] = {19, 17, 15, 88, 71, 54, 25, 14, 30, 66};
    RadixSort(arr, 10, 2);
    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}