#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 2500

// Function prototypes
void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);
void copyArray(int source[], int dest[], int n);

int main() {
    int original[SIZE];
    int arr[SIZE];
    clock_t start, end;
    double cpu_time_used;
    
    // Initialize array with random numbers
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        original[i] = rand() % 100;  // Random numbers 0-99
    }
    
    // Test Selection Sort
    printf("\nOriginal Array:\n");
    // printArray(original, SIZE);
    
    printf("\n1. Selection Sort:\n");
    copyArray(original, arr, SIZE);
    start = clock();
    selectionSort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printArray(arr, SIZE);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    printf("\n2. Bubble Sort:\n");
    copyArray(original, arr, SIZE);
    start = clock();
    bubbleSort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printArray(arr, SIZE);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    printf("\n3. Insertion Sort:\n");
    copyArray(original, arr, SIZE);
    start = clock();
    insertionSort(arr, SIZE);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printArray(arr, SIZE);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap minimum element with first element
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        // Flag for optimization
        int swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // If no swapping occurred, array is sorted
        if (swapped == 0)
            break;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Utility function to copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}