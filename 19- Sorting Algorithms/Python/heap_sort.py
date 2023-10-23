def heap_sort(arr):
    n = len(arr)

    # Build a max heap from the array
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one from the max heap
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = (
            arr[0],
            arr[i],
        )  # Swap the root (maximum element) with the last element
        heapify(arr, i, 0)  # Call heapify on the reduced heap


def heapify(arr, n, i):
    largest = i  # Initialize the largest element as the root
    left = 2 * i + 1  # Left child
    right = 2 * i + 2  # Right child

    # Check if left child exists and is larger than the root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # Check if right child exists and is larger than the largest so far
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If the largest element is not the root, swap them
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]

        # Recursively heapify the affected sub-tree
        heapify(arr, n, largest)


# Example usage:
my_array = [64, 34, 25, 12, 22, 11, 90]
heap_sort(my_array)
print("Sorted array:", my_array)
