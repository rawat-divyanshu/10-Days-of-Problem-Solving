// Take as input a two-d array. Wave print it column-wise.
#include<bits/stdc++.h>
using namespace std;

void printWave(int mat[][10], int m, int n) {
	for(int i = 0; i < n; i++) {
		if(i%2 == 0) {
			for(int j = 0; j < m; j++) {
				cout << mat[j][i] << ", ";
			}
		} else {
			for(int j = m-1; j >= 0; j--) {
				cout << mat[j][i] << ", ";
			}
		}
	}
	cout << "END";
}

int main() {
	int m, n;
	cin >> m >> n;
	int mat[10][10];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	printWave(mat,m,n);
	return 0;
}