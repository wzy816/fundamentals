/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
    
        if(nums.size() == 0){
            return ans;
        }
        int num = nums[0];
        nums.erase(nums.begin()+0);
        if(ans.size() == 0){
            vector<int> c;
            c.push_back(num);
            ans.push_back(c);
        }else{
            int total = ans.size();
            for(int i=0;i<total;++i){
                vector<int> a = ans[i];
                for(int k=0;k<a.size();++k){
                    vector<int> new_a;
                    new_a.assign(a.begin(),a.end());
                    new_a.insert(new_a.begin()+k,num);
                    ans.push_back(new_a);
                }
                ans[i].push_back(num);
            }
        }
        return permute(nums);
    }
};
