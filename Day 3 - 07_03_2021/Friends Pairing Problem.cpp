// Given n friends, each one can remain single or can be paired up with some other friend.
// Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.

// Input Format
// First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

// Constraints
// 1<= n < 30

// Output Format
// Output t lines each line describing the answer.


#include<bits/stdc++.h>
using namespace std;

long waysToPair[31] = {0};

void makeFriendsPair(int n) {
	waysToPair[1] = 1;
	waysToPair[2] = 2;

	for(int i = 3; i <= n; i++) {
		waysToPair[i] = waysToPair[i-1] + (i-1)*waysToPair[i-2];
	}	
}

int main() {
	int t;
	cin >> t;
	int* tc = new int[t];
	int nMAX = 0;

	for(int i = 0; i < t; i++) {
		cin >> tc[i];
		nMAX = max(nMAX,tc[i]);
	}

	makeFriendsPair(nMAX);

	for(int i = 0; i < t; i++) {
		cout << waysToPair[tc[i]] << endl;
	}
	return 0;
}