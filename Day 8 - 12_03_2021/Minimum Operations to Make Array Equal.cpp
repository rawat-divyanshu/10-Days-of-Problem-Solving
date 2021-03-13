// Problem Link : https://leetcode.com/problems/minimum-operations-to-make-array-equal/

class Solution {
public:
    int minOperations(int n) {
        if(n <= 1) return 0;
        int minOp = 0;
        for(int i = 0; i < n/2; i++) {
            minOp += n-(2*i+1);
        }
        return minOp;        
    }
};