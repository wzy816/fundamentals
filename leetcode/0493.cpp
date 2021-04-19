/*
493. Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
*/

// divide-and-conquer, sim. to merge sort
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    int helper(vector<int>& nums, int start, int end){
        if( start >= end ){
            return 0;
        }
        int mid = (start+end)/2;
        int leftTotal = helper(nums, start, mid);
        int rightTotal = helper(nums, mid+1, end);
        sort(nums.begin()+start, nums.begin()+mid+1);
        sort(nums.begin()+mid+1, nums.begin()+end+1);
        int i=start,j=mid+1;
        int total = 0;
        while(i <= mid){
            while( j <= end && nums[i] /2.0 > nums[j]){
                j++;
            }
            total += j-mid-1;
           i++;
        }
        return leftTotal+rightTotal+total;       
    }
};
