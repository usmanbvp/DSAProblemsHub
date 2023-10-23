#Function which takes array and key as arguments and returns index of key in arr
def sequential_search(arr,key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

# Accepts list of numbers and target number
num_list = list(map(int,input("Enter list of numbers: ").split()))
target = int(input("Enter target to search: "))

#Calls the sequentialSearch method
index = sequential_search(num_list,target)

#Prints the index of search element
print(f"Number {target} is at index {index}")


'''
Input/Output:

Enter list of numbers: 34 25 36 23 87
Enter target to search: 23
Number 23 is at index 3

Enter list of numbers: 34 25 36 23 87
Enter target to search: 26
Number 26 is at index -1

'''