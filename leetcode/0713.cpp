/*
713. Subarray Product Less Than K

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
*/

#include<cmath>

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        // two pointer
        int i=0,j=0;
        if (k==0) return 0;
        double K= log(k)-0.00001;
        double pro=log(nums[0]);
        
        while(i<n){
            while(j<n && pro < K){
                j++;
                if(j<n){
                    pro+=log(nums[j]);
                }
            }
            if(j>=i)
                ans += j-i;
            pro-=log(nums[i]);
            i++;
        }
        return ans;
    }
};
