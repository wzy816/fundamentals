/*
1800. Maximum Ascending Subarray Sum
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 is ascending.
*/

// sliding window

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int ans=sum;

        for(int i=1;i<n;++i){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};