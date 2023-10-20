def unique_paths(m, n):
    # Creating a 2D grid with dimensions m x n
    dp = [[0] * n for _ in range(m)]

    # Initializing the first row and first column with 1
    for i in range(m):
        dp[i][0] = 1
    for j in range(n):
        dp[0][j] = 1

    # Dynamic programming to calculate the number of unique paths
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]

    return dp[m - 1][n - 1]

# Example usage
m = 3
n = 7
result = unique_paths(m, n)
print(f"The number of unique paths in a {m}x{n} grid is: {result}")
