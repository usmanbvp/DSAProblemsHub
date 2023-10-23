#Function which takes array and key as arguments and returns index of key in arr
def ternary_search(arr,l,r,key):
    if (r >= l):
        # Find the mid1 and mid2
        mid1 = l + (r - l) //3
        mid2 = r - (r - l) //3
        # Check if key is present at any mid
        if (arr[mid1] == key):
            return mid1
        if (arr[mid2] == key):
            return mid2
        # Since key is not present at mid,
        # check in which region it is present then repeat the Search operation in that region
        if (key < arr[mid1]):
            # The key lies in between l and mid1
            return ternarySearch(arr,l, mid1 - 1, key)
        elif (key > arr[mid2]):
            # The key lies in between mid2 and r
            return ternarySearch(arr,mid2 + 1, r, key)
        else:
            # The key lies in between mid1 and mid2
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key)        
    
    return -1

# Accepts list of numbers and target number
num_list = list(map(int,input("Enter sorted list of numbers: ").split()))
target = int(input("Enter target to search: "))

#Calls the ternarySearch method
index = ternary_search(num_list,0,len(num_list),target)

#Prints the index of search element
print(f"Number {target} is at index {index}")

'''
Input/Output:

Enter sorted list of numbers: 1 2 3 4 5 6 7 8 9 11
Enter target to search: 4
Number 4 is at index 3

'''