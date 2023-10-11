//C++ program to check the validity of a Sudoku board
#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    bool rows[9][9] = {false};
    bool columns[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') {
                int num = board[row][col] - '1'; // Converted this char to integer

                // Check the row
                if (rows[row][num]) return false;
                rows[row][num] = true;

                // Check the column
                if (columns[col][num]) return false;
                columns[col][num] = true;

                // Check the 3x3 box
                int boxIndex = (row / 3) * 3 + col / 3;
                if (boxes[boxIndex][num]) return false;
                boxes[boxIndex][num] = true;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (isValidSudoku(board)) {
        cout << "The Sudoku board is valid." << endl;
    } else {
        cout << "The Sudoku board is not valid." << endl;
    }

    return 0;
}
