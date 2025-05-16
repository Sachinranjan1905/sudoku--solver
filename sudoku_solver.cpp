#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing num in (row, col) is valid
bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    // Check the row
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check the 3x3 grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku board
bool solveSudoku(vector<vector<int>>& board) {
    int row, col;
    bool emptyCell = false;

    // Find an empty cell (denoted by 0)
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) {
            break;
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (!emptyCell) {
        return true;
    }

    // Try numbers 1-9 for the empty cell
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            // Recur to fill the next empty cell
            if (solveSudoku(board)) {
                return true;
            }

            // If placing num doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // If no valid number can be placed, return false
    return false;
}

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // A sample Sudoku puzzle (0 represents empty cells)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Initial Sudoku Board:" << endl;
    printBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
