''' 
There is a staircase with n steps which you can climb up either 1 or 2steps at a time. 
Given n, write a function that returns the number of unique ways you cann cllimb the staircase
n=1 : [1]
n=2 : [1,1], [2]
n=3 : [1,1,1], [1,2], [2,1]
n=4 : [1,1,1,1], [1,1,2], [1,2,1], [2,1,1], [2,2]
'''

def staircase(n, X):
    cache = [0 for _ in range(n+1)]
    cache[0] = 1
    
    for i in range(1, n+1):
        cache[i] += sum(cache[i-step] for step in X if i - step >=0)
    
    return cache[n]

n = 4
X = [1,2]
print(f"No of ways to clim the stairs with {X} steps is {staircase(n,X)}")

'''  
Output:
No of ways to clim the stairs with [1, 2] steps is 5
'''