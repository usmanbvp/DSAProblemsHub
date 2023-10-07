// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 //Link to problem: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/?envType=daily-question&envId=2023-07-31

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX/2));
        
        dp[0][0]=0;
        
        for(int i=1;i<n+1;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1]-'a'+97;
        }
        
        for(int j=1;j<m+1;j++){
            dp[0][j]=dp[0][j-1]+s2[j-1]-'a'+97;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]; 
                }else{
                    int delete_s1 = s1[i-1]-'a'+97 + dp[i-1][j]; 
                    int delete_s2 = s2[j-1]-'a'+97 + dp[i][j-1]; 
                    
                    dp[i][j]=min(delete_s1, delete_s2);
                }
            }
        }
        return dp[n][m];
    }
};
