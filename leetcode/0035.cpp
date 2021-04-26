/*
35. Search Insert Position

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(;i<nums.size();++i){
            if(nums[i] >= target){
                break;
            }
        }
        return i;
    }
};