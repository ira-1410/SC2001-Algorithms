#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mergeSort.h"


void insertionSort(int arr[], int low, int high) {
    for (int i = low+1; i<=high; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=low && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


void hybridSort(int arr[], int low, int high, int S) {
    if (low < high) {
        if (high-low+1 < S) {
            insertionSort(arr, low, high);
        }
        else {
            int mid = low + (high - low) / 2;

            hybridSort(arr, low, mid, S);
            hybridSort(arr, mid + 1, high, S);
            merge(arr, low, mid, high);
        }
        
    }
}
void generateRandomArray(int arr[], int size, int lowest, int highest) {
    srand(time(NULL));
    for (int i=0; i<size; i++) {
        arr[i] = (rand() % (highest-lowest+1)) + lowest;
    }
}

int main() {
    int size=20; //num of elements in the array
    int lowest=1, highest=100; //range of integers to use in the array
    int arr[size];
    generateRandomArray(arr, size, lowest, highest);

    int S=4;

    printf("Original array: \n");
    printArray(arr, size);

    hybridSort(arr, 0, size-1, S);

    printf("\nSorted array: \n");
    printArray(arr, size);

    return 0;
}