#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivot = arr[left];  // Choose a pivot element (first element in this case)
        int i = left;
        int j = right;

        while (i < j) {
            while (i < j && arr[j] >= pivot) {
                j--;
            }
            if (i < j) {
                arr[i] = arr[j];
                i++;
            }

            while (i < j && arr[i] <= pivot) {
                i++;
            }
            if (i < j) {
                arr[j] = arr[i];
                j--;
            }
        }

        arr[i] = pivot;

        // Recursively sort the left and right sub-arrays
        quick_sort(arr, left, i - 1);
        quick_sort(arr, i + 1, right);
    }
}

int main() {
    std::vector<int> input_list;
    int n;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int element;
        std::cin >> element;
        input_list.push_back(element);
    }

    quick_sort(input_list, 0, n - 1);

    std::cout << "Sorted list: ";
    for (int i = 0; i < n; i++) {
        std::cout << input_list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
