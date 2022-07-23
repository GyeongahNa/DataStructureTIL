#include <stdio.h>

//O(n^2), unstable, in-place
void SelectionSort(int arr[], int n) {

    for (int i=0; i<n-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIdx]) minIdx = j;
        }  
        int tmp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = tmp;
    }
} 

int main() {

    int arr[10] = {3, 10, 2, 5, 9, 7, 1, 6, 4, 8};
    SelectionSort(arr, sizeof(arr)/sizeof(int));

    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}