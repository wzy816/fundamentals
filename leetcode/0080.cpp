/*
80. Remove Duplicates from Sorted Array II
Medium

Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
*/

// two pointer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return n;
        }
        
        int i=2,j=2;
        while(j<n){
            if(nums[j] == nums[i-1] && nums[j] == nums[i-2]){
                ++j;
                continue;
            }
            if(j>i){
                nums[i] = nums[j];
            }
            ++i;
            ++j;
        }
        return i;
    }
};