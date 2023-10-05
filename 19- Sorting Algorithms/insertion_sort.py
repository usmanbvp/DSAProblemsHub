def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


# Example..!
my_array = [12, 11, 13, 5, 8]
insertion_sort(my_array)
print("After Insertion Sorting: ", my_array)
