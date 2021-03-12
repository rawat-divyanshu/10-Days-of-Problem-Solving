// Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

// Input Format
// First line contains a single integer N. Next N lines contain N space separated integers.

// Constraints
// N < 1000

// Output Format
// Print N lines with N space separated integers of the rotated array.

#include<iostream>
using namespace std;

void rotateAntiClockwise(int n, int mat[1000][1000]) {
	for(int i = 0, j = n-1; i < j; i++, j--) {
		for(int k = 0; k < n; k++) {
			swap(mat[k][i],mat[k][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			swap(mat[i][j],mat[j][i]);
		}
	}
	// Printing the Matrix
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int mat[1000][1000];
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	rotateAntiClockwise(n,mat);
	return 0;
}