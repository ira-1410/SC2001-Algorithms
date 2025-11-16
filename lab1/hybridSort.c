#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "mergeSort.c"

int insertionSort(int arr[], int low, int high) {
    int comps= 0;
    for (int i= low+1; i<=high; i++) {
        int key= arr[i];
        int j= i-1;
        while (j >= low) {
            comps++;
            if (arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            } else break;
        }
        arr[j+1] = key;
    } return comps;
}

int hybridSort(int arr[], int low, int high, int S) {
    if (low < high) {
        if (high-low+1 < S) {
            return insertionSort(arr, low, high);
        }
        else {
            int mid = low + (high - low) / 2;

            int c1= hybridSort(arr, low, mid, S);
            int c2= hybridSort(arr, mid + 1, high, S);
            int c3= merge(arr, low, mid, high);
            return c1+c2+c3;
        }
    } return 0;
}

void generateRandomArray(int arr[], int size, int lowest, int highest) {
    // range of numbers to be included in the array= [lowest, highest]
    srand(time(NULL));
    for (int i=0; i<size; i++) {
        arr[i] = (rand() % (highest-lowest+1)) + lowest;
    }
}

void copyArray(int arr[], int arr2[], int size){
    for (int i=0; i<size; i++) arr2[i]= arr[i];
}


int main() {
    int size=20; //num of elements in the array
    int lowest=1, highest=100; //range of integers to use in the array
    int arr[size];
    int arr2[size];
    int c1, c2;

    copyArray(arr, arr2, size);
    generateRandomArray(arr, size, lowest, highest);

    printf("Original array: \n");
    printArray(arr, size);

    //first use merge sort
    c1 = mergeSort(arr, 0, size-1);
    printf("\n\nSorted by merge sort with %d comparisons\n", c1);


    int S=4;
    c2 = hybridSort(arr2, 0, size-1, S);
    printf("Sorted by hybrid sort with %d comparisons\n", c2);


    printf("\nSorted array: \n");
    printArray(arr, size);

    return 0;
}