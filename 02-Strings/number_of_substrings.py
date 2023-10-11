# Input : s1 = aab
#         s2 = aaaab
# Output :6
# Substrings of s1 are ["a", "a", "b", "aa", 
# "ab", "aab"]. These all are present in s2. 
# Hence, answer is 6.

def count_substring(s1, s2):
    ans = 0
    #Creates an empty substring
    for i in range(len(s1)):
        s3 = ''
        
        #Adds characters to the substring
        for j in range(i, len(s1)):
            s3 += s1[j]      
            #Checks if the substring is present in s2
            if s2.find(s3) != -1:
                print(s3)
                ans += 1
    return ans

#Driver code
if __name__ == '__main__':
    s1 = 'Where'
    s2 = 'Thereweare'
    print(count_substring(s1, s2))