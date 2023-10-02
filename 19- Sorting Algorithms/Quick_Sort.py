def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    mid = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]

    return quick_sort(left) + mid + quick_sort(right)


# Example of Quick Sort...!
my_array = [12, 11, 13, 5, 8]
sorted_array = quick_sort(my_array)
print("After Quick Sort: ", sorted_array)
