/*
Sort an Array

Given an array of integers nums, sort the array in ascending order.
*/

// implement merge sort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = nums.size();
        helper(nums,0,l-1);
        return nums;
    }
        
    void helper(vector<int>& nums, int start, int end){
        if(start >= end){
            return;
        }
        int mid = (start+end)/2;
        helper(nums, start, mid);
        helper(nums, mid+1, end);
        int i=start;
        int j=mid+1;
        vector<int> temp;
        
        while(i<=mid || j<=end){
            if(j == end+1 || (i!= mid+1 && nums[i] <= nums[j])){
                temp.push_back(nums[i]);
                i++;                
            }else{
                temp.push_back(nums[j]);
                j++;                
            }
        }
        for(int i = 0;i<temp.size();i++){
            nums[start+i] = temp[i];
        }
        return;
    }
};

// implement quick sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<=1){
            return nums;
        }
        helper(nums,0,nums.size()-1);
        return nums;
    }
    void helper(vector<int>& nums, int start, int end){
        if(start < end){
            int i = start,j=end, x = nums[start];
            while(i<j){
                while(i<j && nums[j] > x){
                    j--;
                }
                if(i<j){
                    nums[i] = nums[j];
                    i++;
                }
                while(i<j && nums[i] < x){
                    i++;
                }
                if(i<j){
                    nums[j] = nums[i];
                    j--;
                }
            }
            // here i=j
            nums[i] = x;
            helper(nums,start,i-1);
            helper(nums,i+1,end);
        }
    }
};

