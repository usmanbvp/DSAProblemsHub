#The task is to find the missing number in the array.
#Given an array arr[] of size N-1 with numbers find the missing number from the first N intergers.
#Example 1: arr[] = {1,2,3,5} N = 5
#Output: 4
#Explanation: Given array : 1 2 3 5. Missing element is 4.  

#Example 2: arr[] = {1,2,3,4,5,7,8} N = 8
#Output: 6

def find_missing_number(arr, n):
    #Create a list of zeros
    temp = [0] * (n+1)
    
    for i in range(0, n):
        temp[arr[i] - 1] = 1
        
    for i in range(0, n+1):
        if temp[i] == 0:
            ans = i+1
    print(ans)
    
#Driver code
if __name__ == '__main__':
    arr = [1,2,3,4,5,7,8]
    n = len(arr)
    
    #function call
    find_missing_number(arr, n)
        
        