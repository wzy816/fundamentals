/*
410. Split Array Largest Sum
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9

Example 3:

Input: nums = [1,4,4], m = 3
Output: 4

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= m <= min(50, nums.length)
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // O(N)
        int sum = 0;
        int max = 0;
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            if(nums[i] > max){
                max = nums[i];
            }
        }
        
        // bs for max subarray sum to fit m chunks
        // O(lgN * N)
        int low = max;
        int high = sum;
        while (low < high){
            int mid = (low+high) / 2;

            // condition: check if there exists m subarrays that max sum is mid
            int chunks = m;
            int i = 0;
            int subsum = 0;
            while(i < nums.size() && chunks > 0){
                if( (subsum+ nums[i])> mid) {
                    chunks -=1;
                    subsum = nums[i];
                }else{
                    subsum += nums[i];
                }
                i++;
            }
            
            if(i == nums.size() && chunks > 0){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};