#include <iostream>
using namespace std;

// Function to heapify a subtree (for Max Heap)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Function to heapify (for Min Heap)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Heap sort in Increasing Order (Max Heap)
void heapSortIncreasing(int arr[], int n) {
    // Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}

// Heap sort in Decreasing Order (Min Heap)
void heapSortDecreasing(int arr[], int n) {
    // Build Min Heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Extract elements one by one
    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr1[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << "Original Array: ";
    printArray(arr1, n);

    // Sort Increasing
    heapSortIncreasing(arr1, n);
    cout << "Sorted in Increasing Order: ";
    printArray(arr1, n);

    // Create another array (because arr1 is already sorted now)
    int arr2[] = {12, 11, 13, 5, 6, 7};

    // Sort Decreasing
    heapSortDecreasing(arr2, n);
    cout << "Sorted in Decreasing Order: ";
    printArray(arr2, n);

    return 0;
}
