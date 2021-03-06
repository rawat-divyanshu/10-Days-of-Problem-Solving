#include <bits/stdc++.h>
using namespace std;

// Function to check whether it is safe to place Queen at (i,j)th Grid.
bool isSafe(int n, int board[][10], int i, int j) {
    for(int k = i-1; k >= 0; k--) {
        if(board[k][j] == 1){
            return false;
        }
    }
    for(int a = i-1, b = j-1; a >= 0 && b >= 0; a--, b--) {
        if(board[a][b] == 1){
            return false;
        }
    }
    for(int a = i-1, b = j+1; a >= 0 && b < n; a--, b++) {
        if(board[a][b] == 1){
            return false;
        }
    }
    return true;    
}

bool solveNQueen(int n, int board[][10], int i) {
    // Base Case
    if(i == n) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << board[j][k] << " ";
            }
            cout << endl;
        }
        return true;
        // For all possible Combinations
        
        // cout << endl;
        // return false;
    }

    // Recursive Case
    for(int j = 0; j < n; j++) {
        if(isSafe(n,board,i,j)) {
            board[i][j] = 1;
            bool nextQueen = solveNQueen(n,board,i+1);
            if(nextQueen) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int board[10][10] = {0};
    solveNQueen(n,board,0);
    return 0;
}
