# Program to print hollow diamond pattern

height = int(input("Enter height of diamond: "))
urows, lrows = height//2 + height%2, height//2
k = 1
for urow in range(urows,0,-1):
    print(" "*urow, end="*")
    if urow != urows:
        print(" "*k,end="*")
        k+=2
    print()  
for lrow in range(1,lrows+1):
    print(" "*(lrow+1),end="*") if height%2 != 0 else print(" "*(lrow),end="*")
    if lrow != lrows:
        print(" "*(2*(lrows-lrow)-1),end="*")
    print()
    
    
''' 
Input/Output: 

Enter height of diamond: 6
   *
  * *
 *   *
 *   *
  * *
   *

Enter height of diamond: 5
   *
  * *
 *   *
  * *
   *

'''