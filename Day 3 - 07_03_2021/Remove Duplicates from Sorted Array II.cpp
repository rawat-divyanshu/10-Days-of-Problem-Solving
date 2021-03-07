// Problem Link : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        
        int i = 2, j = 2;
        while(j < n) {
            if(!(nums[i-1] == nums[j] && nums[i-2] == nums[j])) {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;       
    }
};