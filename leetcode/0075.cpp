/*
75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Example 3:
Input: nums = [0]
Output: [0]

Example 4:
Input: nums = [1]

*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return;
        }
        
        int i=0,j=n-1;
        while(true){
            while(i<= n-1 && nums[i]==0){
                i++;
            }
            while(j>= 0 && nums[j]!=0){
                j--;
            }
            if(i>=j) break;
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        j=n-1;
        while(true){
            while(i<= n-1 && nums[i]==1){
                i++;
            }
            while(j>= 0 && nums[j]!=1){
                j--;
            }
            if(i>=j) break;

            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
    }
};
