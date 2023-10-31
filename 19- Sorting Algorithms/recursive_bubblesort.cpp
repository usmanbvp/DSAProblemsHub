#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& arr, int n) {
    // Base case
    if (n == 1) {
        return;
    }

    // Pass 1 of normal Bubble Sort
    int swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            std::swap(arr[i], arr[i + 1]);
            swaps++;
        }
    }

    // If no swaps were made in this pass, the array is already sorted
    if (swaps == 0) {
        return;
    }

    // Recursively sort the remaining elements
    bubbleSort(arr, n - 1);
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
