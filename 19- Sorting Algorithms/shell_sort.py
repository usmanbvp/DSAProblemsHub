def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Start with a large gap and reduce it over multiple passes

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2  # Reduce the gap


# Example usage:
my_array = [64, 34, 25, 12, 22, 11, 90]
shell_sort(my_array)
print("Sorted array:", my_array)
