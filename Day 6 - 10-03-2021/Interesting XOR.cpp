// Problem Link : https://www.codechef.com/MARCH21C/problems/IRSTXOR

#include <bits/stdc++.h>
using namespace std;

long long maxAB(int C) {
  long long maxVal = 0;
  int d = ceil(log2(C));
  long long ur = pow(2,d);

  for(long long A = 1; A < ur; ++A) {
    long long B = C^A;
    if(B < ur && B > 0) {
      maxVal = max(maxVal,A*B);
    } 
  }
  return maxVal;
}

int main() {
  int T;
  cin >> T;
  while(T--) {
    int C;
    cin >> C;
    cout << maxAB(C) << endl;
  }
  return 0;
}