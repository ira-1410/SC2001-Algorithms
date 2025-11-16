#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int low, int mid, int high) {
    int comps = 0;
    int n1 = mid-low+1;
    int n2 = high-mid;

    //create temp arrays for the left and right side
    int left[n1], right[n2];

    for (int i=0; i<n1; i++) { left[i] = arr[low+i]; }
    for (int j=0; j<n2; j++) { right[j] = arr[mid+1+j]; } 

    //merge the temp arrays back into arr[low..high]
    int i=0, j=0, k=low;

    while (i < n1 && j < n2) {
        comps++;
        if (left[i] <= right[j]) { arr[k++]= left[i++]; }
        else { arr[k++]= right[j++]; }
    }

    //copy leftovers of either array
    while (i<n1) { arr[k++]= left[i++]; }
    while (j<n2) { arr[k++]= right[j++]; }

    return comps;
}

//implement merge sort
int mergeSort(int arr[], int low, int high) {
    if (low<high) {
        int mid = low+ (high-low)/2;

        int c1= mergeSort(arr, low, mid);
        int c2= mergeSort(arr, mid+1, high);
        int c3= merge(arr, low, mid, high);

        return c1+c2+c3;
    } else return 0;
}

//helper to print array
void printArray(int arr[], int size) {
    for (int i=0; i<size; i++)
        printf("%d ", arr[i]);
}
