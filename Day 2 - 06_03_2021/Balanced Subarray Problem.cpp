// You are given an array which contains elements equal to only 0 or 1.
// Your task is to find out the maximum length of the subarray which
// contains equal number of zeroes' and one's.

#include<bits/stdc++.h>
using namespace std;

int balancedSubarray(int n, int* nums) {
	int count = 0;
	int ans = 0;
	unordered_map<int,int> umap;
	umap[count] = -1;
	for(int idx = 0; idx < n; idx++) {
		count = nums[idx] == 1 ? count + 1 : count - 1;
		if(umap.find(count) == umap.end()) {
			umap[count] = idx;
		}
		ans = max(ans,idx-umap[count]);
	}
	return ans;
}

int main () {
	int n;
	cin >> n;
	int* nums = new int[n];

	for(int i = 0; i < n; i++)
		cin >> nums[i];

	cout << balancedSubarray(n,nums);
	return 0;
}