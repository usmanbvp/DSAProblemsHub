class Solution {
public:
      //lcs function finds the length of the longest common subsequence of two strings
     int lcs(string text1, string text2) {
        int i,j;
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); 
       //create a 2d vector of size (n+1,m+1) with default value as -1
        for(i=0;i<=n;i++)
            dp[i][0]=0;
        for(j=0;j<=m;j++)
            dp[0][j]=0;
         //assign zero th row and column with zero
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                //if char at i-1 index of string1 matches with char at j-1 index of string2 then fill the vector using this formula
                else
                    dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
                // if char doesn't match then fill the vector using this formula
            }
        }
        return dp[n][m];
         // value at last row and last column contains the length of lcs of two strings
    }
    int longestPalindromeSubseq(string s) {
        string k=s;
        reverse(s.begin(),s.end()); //length of longest palindromic subsequence is equal to the length of lcs of a string and its reverse
        return lcs(k,s);
    }
};
