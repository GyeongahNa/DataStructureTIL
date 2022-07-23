#include <stdio.h>

//O(n^2), stable, in-place
void BubbleSort(int arr[], int n) {

    for (int i=n-1; i>=1; i--) {
        for (int j=0; j<i; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {

    int arr[10] = {3, 10, 2, 5, 9, 7, 1, 6, 4, 8};
    BubbleSort(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}