#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

void printDPTable(int* P, int C) {
    for (int i = 0; i <= C; i++) {
        printf("%d ", P[i]);
    } printf("\n");
}

int* unboundedKnapsack(int numItems, int weights[], int profits[], int C) {
    int* P = malloc((C+1) * sizeof(int));
    for (int i=0; i<C+1; i++) P[i] = 0;

    printf("DP Table (capacity 0 to %d):\n", C);

    for (int capacity=1; capacity<=C; capacity++) {
        for (int item=0; item<numItems; item++) {
            if (weights[item]<= capacity) {
                P[capacity] = MAX(P[capacity], profits[item] + P[capacity - weights[item]]);
            }
        } printf("Iteration %d: \n", capacity);
        printDPTable(P, C);
        printf("\n");
    } 
    return P;
}


int main() {
    int numItems= 3; 
    int weights[] = {4,6,8};
    int profits[] = {7,6,9};
    int C = 14;
    
    int* P = unboundedKnapsack(numItems, weights, profits, C);
    printf("Final DP Table:\n");
    printDPTable(P, C);
    
    free(P);
    return 0;
}