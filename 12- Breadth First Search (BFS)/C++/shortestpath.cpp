#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define the possible directions to move: up, down, left, right, and diagonals
const int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
const int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
        return -1; // No path is possible
    }

    vector<vector<int>> distance(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    distance[0][0] = 1;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if (distance[n - 1][n - 1] == -1) {
        return -1; // No path is possible
    }

    return distance[n - 1][n - 1];
}

int main() {
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    int result = shortestPathBinaryMatrix(grid);
    if (result != -1) {
        cout << "Shortest path length: " << result << endl;
    } else {
        cout << "No path is possible." << endl;
    }
    return 0;
}
