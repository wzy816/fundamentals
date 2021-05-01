/*977. Squares of a Sorted Array
Easy

Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
*/

// stack
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0){
            return ans;
        }
        stack<int> s;
        for(int num : nums){
            int square = num*num;
            if(s.empty() || square <= s.top()){
                s.push(square);
            }else{
                while(!s.empty() && s.top() < square){
                    ans.push_back(s.top());
                    s.pop();
                }
                ans.push_back(square);
            }
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

// two pointer
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if(n == 0){
            return ans;
        }
        int i = 0;
        while(i<n && nums[i] < 0){
            ++i;
        }
        int j = i-1;
        
        while(j>=0 && i<n){
            if(nums[i]>-nums[j]){
                ans.push_back(nums[j] * nums[j]);
                --j;
            }else{
                ans.push_back(nums[i] * nums[i]);
                ++i;                
            }
        }
        while(i<n){
            ans.push_back(nums[i] * nums[i]);
            ++i; 
        }
        while(j>=0){
            ans.push_back(nums[j] * nums[j]);
            --j; 
        }
        
        return ans;
    }
};