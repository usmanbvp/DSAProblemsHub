def find_max_element(arr):
    # Check if the array is empty
    if not arr:
        return None

    # Initialize the maximum element as the first element in the array
    max_element = arr[0]

    # Iterate through the array to find the maximum element
    for num in arr:
        if num > max_element:
            max_element = num

    return max_element

# Example usage:
arr = [5, 2, 9, 1, 5, 6]
max_value = find_max_element(arr)
if max_value is not None:
    print(f"The maximum element in the array is {max_value}")
else:
    print("The array is empty.")
