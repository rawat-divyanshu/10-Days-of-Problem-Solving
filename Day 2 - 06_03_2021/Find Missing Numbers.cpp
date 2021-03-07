// Given an array of n unique integers where each element in the array is in range [1, n].
// The array has all distinct elements and size of array is (n-2).
// Hence Two numbers from the range are missing from this array. Find the two missing numbers.

#include <bits/stdc++.h>
using namespace std;

void findMissingNumbers(int n, int* nums) {
    int numsXOR = 0;
    for(int i = 0; i < n-2; i++) {
        numsXOR ^= nums[i];
    }
    for(int i = 1; i <= n; i++) {
        numsXOR ^= i;
    }
    int setBIT = numsXOR & ~(numsXOR - 1);

    int num1 = 0, num2 = 0;
    for(int i = 0; i < n-2; i++) {
        if(nums[i] & setBIT) {
            num1 ^= nums[i];
        } else {
            num2 ^= nums[i];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i & setBIT) {
            num1 ^= i;
        } else {
            num2 ^= i;
        }
    }
    cout << "Missing Numbers : " << num1 << " " << num2 << endl;
}

int main() {
    int n;
    cin >> n;
    int* nums = new int[n-2];
    
    for(int i = 0; i < n-2; i++)
        cin >> nums[i];

    findMissingNumbers(n,nums);
    return 0;
}
