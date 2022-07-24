#include <stdio.h>

void swap(int arr[], int idx1, int idx2) {

    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int GetMedianThree(int arr[], int left, int right) {

    int candidates[3] = {left, (left+right)/2, right};

    for (int i=2; i>=1; i--) {
        for (int j=0; j<i; j++) {
            if (arr[candidates[j]] > arr[candidates[j+1]]) 
                swap(candidates, j, j+1);
        }
    }
    return candidates[1];
}

int Partition(int arr[], int left, int right) {

    int pivot = arr[left];
    int low = left+1;
    int high = right;

    printf("피벗: %d\n", pivot);
    while (low <= high) {
        while (low <= right && arr[low] <= pivot) low++;
        while (high >= (left+1) && arr[high] >= pivot) high--;
        if (low <= high) swap(arr, low, high);
    }
    swap(arr, left, high);
    return high;
}

void medianThreeQuickSort(int arr[], int left, int right) {

    if (left < right) {
        int medianIdx = GetMedianThree(arr, left, right);
        swap(arr, left, medianIdx);
        int pivotIdx = Partition(arr, left, right);
        medianThreeQuickSort(arr, left, pivotIdx-1);
        medianThreeQuickSort(arr, pivotIdx+1, right);
    }
}

int main() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    medianThreeQuickSort(arr, 0, 9);
    for (int i=0; i<10; i++) printf("%d ", arr[i]);
    return 0;
}

/*
output: 
피벗: 5
피벗: 2
피벗: 3
피벗: 8
피벗: 6
피벗: 9
1 2 3 4 5 6 7 8 9 10

개선 전 코드로 1 ~ 10까지의 수를 정렬하면 9개의 피벗이 선택되지만,
left, mid, right 중 중앙값을 피벗으로 설정하면 선택된 피벗의 수가 줄어듦
/*