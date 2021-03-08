#include <bits/stdc++.h>
using namespace std;

int compare(const void* a, const void* b) {
	const int* x = (int*) a;
	const int* y = (int*) b;

	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;

	return 0;
}

void twoNumberSum(int* nums, int n, int target) {
    int l = 0, r = n-1;

    while(l < r) {
        if(nums[l] + nums[r] > target) {
            r--;
        } else if (nums[l] + nums[r] < target) {
            l++;
        } else {
            cout << nums[l] << " " << nums[r] << endl;
            return;
        }
    }
    cout << "No Possible Pair Found." << endl;
    return;    
}


int main() {
    int n, target;
    cin >> n;
    int* nums = new int[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> target;

    qsort(nums,n,sizeof(nums[0]),compare);

    twoNumberSum(nums,n,target);
    return 0;
}
