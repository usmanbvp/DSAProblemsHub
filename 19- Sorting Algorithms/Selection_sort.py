def selection_sort(arr):
    n = len(arr)

    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]  # Swap the min element..!


# Example of selection sort...!
my_array = [12, 11, 13, 5, 8]
selection_sort(my_array)
print("After Selection Sorting: ", my_array)
