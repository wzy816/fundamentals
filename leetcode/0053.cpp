/*
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
*/

// sliding window ?

// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int state[nums.size()];
        int ans = nums[0];
        state[0] = nums[0];
        for(int i=1;i<nums.size();++i){
            state[i] = max(state[i-1]+nums[i], nums[i]);
            if(state[i]>ans){
                ans = state[i];
            }
        }
        return ans;
    }
};