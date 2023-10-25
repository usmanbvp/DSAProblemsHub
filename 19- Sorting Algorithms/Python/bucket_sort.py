def bucket_sort(arr):
    # Find the minimum and maximum values in the input array
    min_val = min(arr)
    max_val = max(arr)

    # Calculate the range for each bucket and the number of buckets
    bucket_range = (max_val - min_val) / len(arr)
    num_buckets = len(arr)

    # Create empty buckets
    buckets = [[] for _ in range(num_buckets)]

    # Distribute elements into buckets
    for num in arr:
        index = int((num - min_val) / bucket_range)
        buckets[index].append(num)

    # Sort each bucket (we'll use Insertion Sort here)
    for i in range(num_buckets):
        buckets[i].sort()

    # Concatenate sorted buckets to get the final sorted array
    sorted_array = []
    for bucket in buckets:
        sorted_array.extend(bucket)

    return sorted_array


# Example usage:
my_array = [64, 34, 25, 12, 22, 11, 90]
sorted_array = bucket_sort(my_array)
print("Sorted array:", sorted_array)
