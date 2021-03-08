// Problem Link : https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int n = nums.size();

        if(n < 3) return {};

        set<vector<int>> ans;
        vector<vector<int>> res;

        for(int i = 0; i < n-2; i++) {
            int l = i+1;
            int r = n-1;

            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) {
                    r--;
                } else if(sum < 0) {
                    l++;
                } else {
                    ans.insert({nums[i], nums[l++], nums[r--]});
                }
            }
        }
        copy(ans.begin(), ans.end(),back_inserter(res));
        return res;
    }
};