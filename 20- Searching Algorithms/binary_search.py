#Function which takes array and key as arguments and returns index of key in arr
def binary_search(arr,key):
    low, high = 0, len(num_list)-1

    # Search the sorted array using binary search algorithm
    while low <= high:
        #calculates the middle index
        mid = (low+high)//2
        #if key is the middle element then return mid as index
        if num_list[mid] == key:
            return mid
        #if key lesser than middle element then the key is at left of mid
        elif num_list[mid] > key:
            high = mid - 1
        #if key greater than middle element then the key is at right of mid
        else:
            low = mid + 1
    return -1

# Accepts list of numbers and target number
num_list = list(map(int,input("Enter sorted list of numbers: ").split()))
target = int(input("Enter target to search: "))

#Calls the binarySearch method
index = binary_search(num_list,target)

#Prints the index of search element
print(f"Number {target} is at index {index}")

'''
Input/Output:

Enter sorted list of numbers: 12 15 46 56 75 89
Enter target to search: 75
Number 75 is at index 4

'''