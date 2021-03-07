// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

// Constraints
// 1<=t<=100 1<=n<=90

// Output Format
// Print the number of all possible binary strings.

#include<bits/stdc++.h>
using namespace std;

long arr[91][2] = {0};

void calcBinaryStrings(int n) {
	arr[1][0] = 1;
	arr[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		arr[i][0] = arr[i-1][0] + arr[i-1][1];
		arr[i][1] = arr[i-1][0];
	}
}

long binaryStrings(int n) {
	return arr[n][0] + arr[n][1];
}

int main() {
	int t;
	cin >> t;
	int* tc = new int[t];
	int nMax = INT_MIN;
	for(int i = 0; i < t; i++) {
		cin >> tc[i];
		nMax = max(nMax,tc[i]);
	}
	calcBinaryStrings(nMax);
	for(int i = 0; i < t; i++) {
		cout << binaryStrings(tc[i]) << endl;
	}
	return 0;
}