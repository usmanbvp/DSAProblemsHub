#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;
        
        // Define directions for BFS (up, down, left, right)
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        
        // Perform BFS from each land cell
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    grid[i][j] = '0'; // Mark the current cell as visited
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        // Explore all four directions
                        for (int k = 0; k < 4; ++k) {
                            int newX = x + dirX[k];
                            int newY = y + dirY[k];
                            
                            // Check if the new cell is within bounds and is part of an island
                            if (newX >= 0 && newX < numRows && newY >= 0 && newY < numCols && grid[newX][newY] == '1') {
                                grid[newX][newY] = '0'; // Mark the new cell as visited
                                q.push({newX, newY});
                            }
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int islands = solution.numIslands(grid);
    cout << "Number of Islands: " << islands << endl;

    return 0;
}
