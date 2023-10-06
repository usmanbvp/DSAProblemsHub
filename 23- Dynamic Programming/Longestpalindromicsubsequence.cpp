class Solution {
public:
     int lcs(string text1, string text2) {
        int i,j;
        int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(i=0;i<=n;i++)
            dp[i][0]=0;
        for(j=0;j<=m;j++)
            dp[0][j]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string k=s;
        reverse(s.begin(),s.end());
        return lcs(k,s);
    }
};
