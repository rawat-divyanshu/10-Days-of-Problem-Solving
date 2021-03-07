// Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
// The output strings should be printed in the sorted order considering '(' has higher value than ')'.

// Input Format
// Single line containing an integral value 'n'.

// Constraints
// 1<=n<=11

// Output Format
// Print the balanced parentheses strings with every possible solution on new line.

#include <bits/stdc++.h>
using namespace std;

void printBalancedParentheses(int op, int cp, char* pattern, int currentIndex) {
    if(op == 0 && cp == 0) {
        pattern[currentIndex] = '\0';
        cout << pattern << endl;        
    }
    if(op > 0) {
        pattern[currentIndex] = '(';
        printBalancedParentheses(op-1,cp,pattern,currentIndex+1);
    }
    if(cp > op) {
        pattern[currentIndex] =')';
        printBalancedParentheses(op,cp-1,pattern,currentIndex+1);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    char* pattern = new char[2*n+1];
    printBalancedParentheses(n,n,pattern,0);
    return 0;
}
