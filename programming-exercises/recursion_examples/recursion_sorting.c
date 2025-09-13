#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Recursive binary search
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }
        
        return binarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

// Simple recursive bubble sort
void bubbleSort(int arr[], int n) {
    if (n == 1) {
        return;
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    
    bubbleSort(arr, n - 1);
}

// Function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test factorial
    printf("Factorial of 5: %d\n", factorial(5));
    
    // Test fibonacci
    printf("Fibonacci of 7: %d\n", fibonacci(7));
    
    // Test sorting
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    // Test binary search
    int target = 25;
    int result = binarySearch(arr, 0, n - 1, target);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }
    
    return 0;
}