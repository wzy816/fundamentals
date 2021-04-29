/*
1004. Max Consecutive Ones III

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

*/

// sliding window
// same idea as 0424

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int count[2] = {0};
        int ans =0;
        int n = nums.size();
        while(j<n){
            
            count[nums[j]]++;
            if((j-i+1) - count[1] > k){
                count[nums[i]]--;
                ++i;
            }
            
            ans = max(j-i+1, ans);
            ++j;
        }
        return ans;
    }
};