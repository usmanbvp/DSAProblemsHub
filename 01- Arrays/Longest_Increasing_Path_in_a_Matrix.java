// 329. Longest Increasing Path in a Matrix

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        // Create a 2D array to store previously computed results for each cell in the
        // matrix.
        Integer[][] cache = new Integer[matrix.length][matrix[0].length];
        int longest = 0; // Initialize the variable to keep track of the longest increasing path.

        // Iterate through each cell in the matrix.
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                // Compute the longest increasing path starting from the current cell
                // and update the 'longest' variable with the maximum path length.
                longest = Math.max(longest, dfs(i, j, -1, matrix, cache));
            }
        }

        // Return the overall longest increasing path in the matrix.
        return longest;
    }

    // Recursive function to find the longest increasing path starting from a given
    // cell.
    public int dfs(int row, int col, int parent, int[][] matrix, Integer[][] cache) {
        // Base case: If the current cell is out of bounds or doesn't form an increasing
        // path,
        // return 0 as there's no path from this cell.
        if (row < 0 || row == matrix.length || col < 0 || col == matrix[0].length ||
                matrix[row][col] <= parent) {
            return 0;
        }

        // If the result for this cell has already been computed, return it from the
        // cache.
        if (cache[row][col] != null) {
            return cache[row][col];
        }

        // Recursive calls in four possible directions (up, down, left, and right),
        // incrementing the path length by 1 for each step.
        int up = 1 + dfs(row + 1, col, matrix[row][col], matrix, cache);
        int down = 1 + dfs(row - 1, col, matrix[row][col], matrix, cache);
        int left = 1 + dfs(row, col - 1, matrix[row][col], matrix, cache);
        int right = 1 + dfs(row, col + 1, matrix[row][col], matrix, cache);

        // Find the maximum path length among all possible directions.
        int longestPath = Math.max(Math.max(up, down), Math.max(left, right));

        // Cache the result for this cell to avoid recomputation.
        cache[row][col] = longestPath;

        // Return the longest path starting from the current cell.
        return longestPath;
    }
}
