#include <bits/stdc++.h>
using namespace std;

bool ratInAMaze(char maze[10][10], int soln[10][10], int i, int j, int m, int n) {
    if(i == m && j == n) {
        soln[m][n] = 1;
        for(int a = 0; a <= m; a++) {
            for(int b = 0; b <= n; b++) {
                cout << soln[a][b] << " ";
            }
            cout << endl;
        }
        cout << endl;    
        return true;
    }

    if(i > m || j > n) return false;
    if(maze[i][j] == 'X') return false;

    soln[i][j] = 1;

    bool rightSuccess = ratInAMaze(maze,soln,i,j+1,m,n);
    bool downSuccess = ratInAMaze(maze,soln,i+1,j,m,n);

    soln[i][j] = 0;

    if(rightSuccess || downSuccess) {
        return true;
    }
    return false;
}

int main() {
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };

    int soln[10][10] = {0};
    int m = 4, n= 4;

    bool ans = ratInAMaze(maze,soln,0,0,m-1,n-1);

    if(!ans) {
        cout << "No Path Exists" << endl;
    }
    return 0;
}
