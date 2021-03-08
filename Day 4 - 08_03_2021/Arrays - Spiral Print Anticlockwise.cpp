// Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

// Input Format
// Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

// Constraints
// Both M and N are between 1 to 10.

// Output Format
// All M * N integers separated by commas with 'END' written in the end(as shown in example).

// Sample Input
// 4 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44

// Sample Output
// 11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END

#include <bits/stdc++.h>
using namespace std;

void spiralPrintA(int m, int n, int arr[10][10]) {
    int r = 0, c = 0;

    while(r <= m && c <= n) {
        for(int i = r; i <= m; i++) {
            cout << arr[i][c] << ", ";
        }
        c++;

        for(int i = c; i <= n; i++) {
            cout << arr[m][i] << ", ";
        }
        m--;

        if(c <= n) {
            for(int i = m; i >= r; i--) {
                cout << arr[i][n] << ", ";
            }
            n--;
        }

        if(r <= m) {
            for(int i = n; i >= c; i--) {
                cout << arr[r][i] << ", ";
            }
            r++;
        }
    }
    cout << "END" << endl;
}

int main() {
    int m,n;
    cin >> m >> n;
    int arr[10][10];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    spiralPrintA(m-1,n-1,arr);
    return 0;
}
