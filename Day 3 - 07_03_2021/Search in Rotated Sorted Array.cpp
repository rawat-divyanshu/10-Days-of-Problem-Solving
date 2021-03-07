// Problem Link : https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return rotatedArraySearch(nums,target,0,nums.size()-1);        
    }
    
    int rotatedArraySearch(vector<int>& nums, int target, int left, int right) {
        if(right < left) return -1;
        
        int mid = left + (right - left)/2;
        
        if(nums[mid] == target) return mid;
        
        if(nums[mid] > nums[nums.size()-1]) {
            if(target > nums[mid] || target < nums[0]) {
                return rotatedArraySearch(nums,target,mid+1,right);
            } else {
                return rotatedArraySearch(nums,target,left,mid-1);
            }
        } else {
            if(target < nums[mid] || target > nums[nums.size()-1]) {
                return rotatedArraySearch(nums,target,left,mid-1);
            } else {
                return rotatedArraySearch(nums,target,mid+1,right);
            }
        }
    }
};