#include <stdio.h>

//최선, 평균: O(nlong), 최악: O(N^2), unstable, in place
void swap(int arr[], int idx1, int idx2) {

    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int Partition(int arr[], int left, int right) {

    int pivot = arr[left];
    int low = left+1;
    int high = right;

    while (low <= high) {

        while (low <= right && arr[low] <= pivot) low++;
        while (high >= left+1 && arr[high] >= pivot) high--;
        if (low <= high) swap(arr, low, high);
    }
    
    swap(arr, left, high);
    return high;
}    

void QuickSort(int arr[], int left, int right) {

    if (left < right) {
        int pivotIdx = Partition(arr, left, right);
        QuickSort(arr, left, pivotIdx-1);
        QuickSort(arr, pivotIdx+1, right);
    }
}

int main() {

    int arr[10] = {2, 1, 3, 4, 5, 8, 7, 9, 6, 10};
    QuickSort(arr, 0, 9);
    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}