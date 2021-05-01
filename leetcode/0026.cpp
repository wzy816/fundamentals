/*
26. Remove Duplicates from Sorted Array
Easy

Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/


// two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int i=1, j=1;
        while(j<n){
            if(nums[j] == nums[i-1]){
                ++j;
            }else{
                nums[i] = nums[j];
                ++i;
            }
        }
        return i;
    }
};