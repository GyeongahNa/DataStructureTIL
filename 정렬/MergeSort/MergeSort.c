#include <stdio.h>
#include <stdlib.h>

//O(nlogn), stable, not in-place
void MergeTwoArea(int arr[], int left, int mid, int right) {

    int lIdx = left;
    int rIdx = mid+1;
    int tmpIdx = left;
    int* tmp = (int*)malloc(sizeof(int)*(right+1));

    while (lIdx <= mid && rIdx <= right) {
        if (arr[lIdx] <= arr[rIdx]) tmp[tmpIdx++] = arr[lIdx++];
        else tmp[tmpIdx++] = arr[rIdx++];
    }

    if (lIdx > mid) {
        for (int i=rIdx; i<=right; i++) tmp[tmpIdx++] = arr[i];
    }
    else {
        for (int i=lIdx; i<=mid; i++) tmp[tmpIdx++] = arr[i];
    }

    for (int i=left; i<=right; i++) arr[i] = tmp[i];
    free(tmp);
}

void MergeSort(int arr[], int left, int right) {

    if (left < right) {
        int mid = (left+right)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

int main() {

    int arr[8] = {1, 4, 5, 7, 2, 3, 6, 8};
    MergeSort(arr, 0, 7);
    for (int i=0; i<8; i++) printf("%d ", arr[i]);
    return 0;
}