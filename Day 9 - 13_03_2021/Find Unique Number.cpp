// We are given an array containg n numbers. All the numbers are present thrice except for one number which is only present once.
// Find the unique number. Only use - bitwise operators, and no extra space.

// Input Format
// First line contains the number n. Second line contains n space separated number.

// Constraints
// N < 10^5

// Output Format
// Output a single line containing the unique number

// Sample Input
// 7
// 1 1 1 2 2 2 3

// Sample Output
// 3

#include<iostream>
using namespace std;

int bitCount = 32;

int findUniqueNumber(int n, int* nums) {
	int ans = 0;
	for(int i = 0; i < bitCount; i++) {
		int bitPosSum = 0;
		for(int j = 0; j < n; j++) {
			if ((1 << i) & nums[j]) bitPosSum++;
		}
		if(bitPosSum % 3 == 1) {
			ans += (1 << i);
		}
	}
	return ans;
}


int main() {
	int n;
	cin >> n;
	int* nums = new int[n];

	for(int i = 0; i < n; i++)
		cin >> nums[i];

	cout << findUniqueNumber(n,nums) << endl;
	return 0;
}