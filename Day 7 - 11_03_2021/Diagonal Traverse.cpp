// Given an array of M x N elements (M rows, N columns), return all elements of the array in diagonal order .

// Input Format
// Two integers M(row) and N(column) and Second line contains N*M space separated integers denoting the elements of Array.

// Constraints
// The total number of elements of the given array will not exceed 10,000.

// Output Format
// display Diagonal

// Sample Input
// 3 3
// 1 2 3 4 5 6 7 8 9

// Sample Output
// 1 2 4 7 5 3 6 8 9 

#include<iostream>
using namespace std;

void diagonalTraverse(int m, int n, int** mat) {
	int totalDiagonals = m + n - 1;
	int i = 0, j = 0;
	while(totalDiagonals > 0) {
		while(i >= 0 && j < n) {
			cout << mat[i--][j++] << " ";
		}
		--totalDiagonals;
		if(j >= n) {
			j = n-1;
			i += 2;
		} else {
			i += 1;
		}
		if(totalDiagonals > 0) {
			while(j >= 0 && i < m) {
				cout << mat[i++][j--] << " ";
			}
			--totalDiagonals;
			if(i >= m) {
				i = m-1;
				j += 2;
			} else {
				j += 1;
			}
		}		
	}
}

int main() {
	int m, n;
	cin >> m >> n;

	int** mat = new int*[m];
	for(int i = 0; i < m; i++) {
		mat[i] = new int[n];
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	diagonalTraverse(m,n,mat);
	return 0;
}