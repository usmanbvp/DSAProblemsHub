
#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(int m, int n, vector<vector<int>>& dp) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue; 
            }
            int up = 0;
            int left = 0;
            if (i > 0)
                up = dp[i - 1][j];

            // If we are not at the first column (j > 0), update 'left' with the value from the cell to the left.
            if (j > 0)
                left = dp[i][j - 1];

            // Calculate the number of ways to reach the current cell by adding 'up' and 'left'.
            dp[i][j] = up + left;
        }
    }

    
    return dp[m - 1][n - 1];
}

int countWays(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countWaysUtil(m, n, dp);
}

int main() {
    int m = 3;
    int n = 2;
    cout << "Number of ways to reach (" << m - 1 << ", " << n - 1 << "): " << countWays(m, n) << endl;

    return 0;
}
