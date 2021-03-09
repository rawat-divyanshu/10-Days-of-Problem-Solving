// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
// The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
// To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
// What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// * Line 1: Two space-separated integers: N and C
// * Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

#include <bits/stdc++.h>
using namespace std;

bool ableToPlaceCow(int N, int* stalls, int C, int min_sep) {
    int last_cow = stalls[0];
    int noOfCowsPlaced = 1;

    for(int i = 1; i < N; i++) {
        if(stalls[i] - last_cow >= min_sep) {
            last_cow = stalls[i];
            noOfCowsPlaced++;
            if(noOfCowsPlaced == C) {
                return true;
            }
        }
    }
    return false;
}

int largestMinDistance(int N, int* stalls, int C) {
    int s = 0;
    int e = stalls[N-1] - stalls[0];
    int ans = 0;

    while(s <= e) {
        int m = s + (e-s)/2;

        bool wereCowsPlaced = ableToPlaceCow(N,stalls,C,m);

        if(wereCowsPlaced) {
            ans = m;
            s = m+1;
        } else {
            e = m-1;
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int N,C;
        cin >> N >> C;
        int* stalls = new int[N];

        for(int i = 0; i < N; i++)
            cin >> stalls[i];

        sort(stalls,stalls+N);

        cout << largestMinDistance(N,stalls,C) << endl;        
    }
    return 0;
}
