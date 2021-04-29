/*
209. Minimum Size Subarray Sum

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/

// sliding window

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i=0,j=1,total=nums[0];
        for(int i=0;i<nums.size();++i){
            if(nums[i] == target){
                return 1;
            }

            while(total < target && j < nums.size()){
                total += nums[j];
                ++j;
            }
            if(total >= target){
                ans = min(ans, j-i);
            }

            total -= nums[i];
        }
        return ans == INT_MAX? 0 : ans;
    }
};
