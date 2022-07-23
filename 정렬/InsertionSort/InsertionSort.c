#include <stdio.h>

//최선: O(n), 최악: O(n^2), stable, in-place
void InsertionSort(int arr[], int n) {

    for (int i=1; i<n; i++) {
        int j;
        int data = arr[i];
        for (j=i-1; j>=0; j--) {
            if (arr[j] > data) arr[j+1] = arr[j];
            else break;
        }
        arr[j+1] = data;
    }
}

int main() {

    int arr[10] = {3, 10, 2, 5, 9, 7, 1, 6, 4, 8};
    InsertionSort(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}