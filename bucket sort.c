
#include <stdio.h>
#include <stdlib.h>
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void bucketSort(float arr[], int n) {
    float buckets[n][n];
    int bucketCount[n];
    for (int i = 0; i < n; i++)
        bucketCount[i] = 0;
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        buckets[index][bucketCount[index]++] = arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (bucketCount[i] > 0)
            insertionSort(buckets[i], bucketCount[i]);
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    bucketSort(arr, n);
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    return 0;
}
