/*
300. Longest Increasing Subsequence

Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

// dp -> O(n*n)
// here -> O(nlogn)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        int tail[n];
        fill(tail, tail+n,10001);
        for(int i=0;i<nums.size();++i){
            int num = nums[i];
            auto pos = lower_bound(tail,tail+n, num) - tail;
            if(tail[pos] > num){
                tail[pos] = num;
            };
        }
        return lower_bound(tail,tail+n, 10001) - tail;
    }
};