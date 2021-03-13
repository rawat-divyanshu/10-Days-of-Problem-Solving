// You are given with Q queries each query containing two integers a and b.
// Your task is to count the no of set-bits in for all numbers between a and b (both inclusive)

// Input Format
// Read Q - No of Queries, Followed by Q lines containing 2 integers a and b.

// Constraints
// Q,a,b are integers.

// Output Format
// Q lines, each containing an output for your query.

#include <bits/stdc++.h>
using namespace std;

int setBitSumUptoN(int N) {
    if(N <= 1) return N;
    int x = log2(N);
    int sum = ((1 << (x-1))*x) + (N - (1 << x) + 1) + setBitSumUptoN(N - (1 << x));
    return sum;
}

int setBitSumInRange(int l, int r) {
    return setBitSumUptoN(r) - setBitSumUptoN(l-1);
}

int main() {
    int Q;
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
        cout << setBitSumInRange(l,r) << endl;
    }
    return 0;
}
