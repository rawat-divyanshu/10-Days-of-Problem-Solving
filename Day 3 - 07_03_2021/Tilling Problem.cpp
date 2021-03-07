// Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m .
// A tile can either be placed horizontally or vertically.

// Input Format
// First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
// The first line of each test case contains two integers N and M.

// Constraints
// 1 <= T<= 1000
// 1 <= N,M <= 100000

// Output Format
// Print answer for every test case in a new line modulo 10^9+7.

#include<bits/stdc++.h>
using namespace std;

int waysToTile(int n, int m, int* dp) {
    if(n < 0) return 0;
    if(n == 0) return dp[n] = 0;
    if(n == 1 || n < m) return dp[n] = 1;
    if(n == m) return dp[n] = 2;
    
    int res = 0;
    if(dp[n-1] != -1) {
        res += dp[n-1];
    } else {
        res += waysToTile(n-1,m,dp);
    }
    if(dp[n-m] != -1) {
        res += dp[n-m];
    } else {
        res += waysToTile(n-m,m,dp);
    }
    return dp[n] = res%1000000007;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
        int* dp = new int[n+1];
        for(int i = 0; i <= n; i++) {
            dp[i] = -1;
        }
		cout << waysToTile(n,m,dp) << endl;
	}
	return 0;
}