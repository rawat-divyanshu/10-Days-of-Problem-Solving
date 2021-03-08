// Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
// Note:- If the x is not found in the array, print -1 -1

// Input Format
// The first line contains two integers n and x. The second line contains n spaced integers.

// Constraints
// 1 < n < 10^8
// -1 < arr[i] < 10^9

// Output Format
// Print index of the first and last occurrences of the number x with a space in between.

#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int* nums, int n, int target) {
    int l = 0, r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = l + (r-l)/2;

        if(nums[mid] == target) {
            ans = mid;
            r = mid-1;
        } else if(nums[mid] > target) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int lastOccurence(int* nums, int n, int target) {
    int l = 0, r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = l + (r-l)/2;

        if(nums[mid] == target) {
            ans = mid;
            l = mid+1;
        } else if(nums[mid] > target) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return ans;
}

int main() {
    int n, target;
    cin >> n >> target;
    int* nums = new int[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << firstOccurence(nums,n,target) << " " << lastOccurence(nums,n,target) << endl;
    return 0;
}
