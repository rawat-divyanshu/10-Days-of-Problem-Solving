#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][9], int n, int i, int j, int k) {
    for(int a = 0; a < n; a++) {
        if(board[i][a] == k || board[a][j] == k) {
            return false;
        }
    }
    int rn = sqrt(n);
    int startRow = (i/rn)*rn;
    int startCol = (j/rn)*rn;
    for(int a = startRow; a < startRow + rn; a++) {
        for(int b = startCol; b < startCol + rn; b++) {
            if(board[a][b] == k) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int board[][9], int n, int i, int j) {
    // Base Case
    if(i == n) {
        for(int a = 0; a < n; a++) {
            for(int b = 0; b < n; b++) {
                cout << board[a][b] << " ";
            }
            cout << endl;
        }

        return true;
    }
    // Recursive Case
    if(j == n) {
        return solveSudoku(board,n,i+1,0);
    }
    if(board[i][j] != 0) {
        return solveSudoku(board,n,i,j+1);
    }
    for(int k = 1; k <= n; k++) {
        if(isSafe(board,n,i,j,k)) {
            board[i][j] = k;
            bool solveRemainingSudoku = solveSudoku(board,n,i,j+1);
            if(solveRemainingSudoku) {
                return true;
            }
        }
    }
    board[i][j] = 0;
    return false;
}

int main() {
    int board[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    int n = 9;
    int ans = solveSudoku(board,n,0,0);
    if(!ans) {
        cout << "Invalid Sudoku. Can't be solved." << endl;
    }
    return 0;
}
