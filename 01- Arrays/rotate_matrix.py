def rotate_matrix(matrix):
    n = len(matrix)

    # Transpose the matrix (swap rows and columns)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Reverse each row to complete the rotation
    for i in range(n):
        matrix[i].reverse()


# Example usage:
matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

rotate_matrix(matrix)

# The matrix is now rotated by 90 degrees
for row in matrix:
    print(row)


# Explanation:

# First, we transpose the matrix by swapping the elements across the main diagonal. This effectively swaps rows and columns.

# Then, for each row, we reverse the elements. This step completes the 90-degree clockwise rotation.

# By following these two steps, the original matrix is rotated in-place. The time complexity of this solution is O(N^2), where N is the number of rows (or columns) in the matrix, because we visit each element once during the transpose operation and once during the reverse operation.
