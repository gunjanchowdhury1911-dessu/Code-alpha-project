#include <iostream>
#include <cmath>
using namespace std;

int N;
int grid[20][20];   // supports up to 20x20

// Check if safe to place number
bool isSafe(int row, int col, int num) {

    // Row check
    for(int x = 0; x < N; x++)
        if(grid[row][x] == num)
            return false;

    // Column check
    for(int x = 0; x < N; x++)
        if(grid[x][col] == num)
            return false;

    // Subgrid check
    int root = sqrt(N);
    int startRow = row - row % root;
    int startCol = col - col % root;

    for(int i = 0; i < root; i++)
        for(int j = 0; j < root; j++)
            if(grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Backtracking solver
bool solveSudoku() {

    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {

            if(grid[row][col] == 0) {

                for(int num = 1; num <= N; num++) {

                    if(isSafe(row, col, num)) {

                        grid[row][col] = num;

                        if(solveSudoku())
                            return true;

                        grid[row][col] = 0; // backtrack
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main() {

    cout << "Enter size of Sudoku (4, 9, 16...): ";
    cin >> N;

    int root = sqrt(N);

    // Validate N
    if(root * root != N) {
        cout << "Invalid size! N must be perfect square (4, 9, 16...)\n";
        return 0;
    }

    cout << "Enter Sudoku Grid (0 for empty cells):\n";

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> grid[i][j];

    if(solveSudoku()) {

        cout << "\nSolved Sudoku:\n";

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                cout << grid[i][j] << " ";
            cout << endl;
        }
    }
    else {
        cout << "No solution exists.\n";
    }

    return 0;
}
