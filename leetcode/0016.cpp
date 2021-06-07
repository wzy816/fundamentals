/*
16. 3Sum Closest
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers.
You may assume that each input would have exactly one solution.
*/

#include <cmath>  
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;++i){
            int j = i+1,k=n-1;
            while(j < k){
                int total = nums[i]+nums[j]+nums[k];
                if(abs(total-target) < abs(ans-target)){
                    ans = total;
                }
                if(total < target){
                    j++;
                }else if(total > target){
                    k--;
                }else{
                    return ans;
                }
            }
            
        }
        return ans;
    }
};
