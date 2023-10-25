def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False  # for code optimization purposes only

        # last i elements are already in place..!
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]  # Swap the elements
                swapped = True

        # if no two elements are swapped in the inner loop, then array is alreay Sorted
        if not swapped:
            break


# Example of bubble Sort...!
my_array = [12, 11, 13, 5, 8]
bubble_sort(my_array)
print("After Bubble Sorting: ", my_array)
