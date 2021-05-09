/*
15. 3Sum

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*、

// two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if(n <=2){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            int a=nums[i];
            while(j < k){
                if(a+nums[j]+nums[k]>0){
                    --k;
                }else if (a+nums[j]+nums[k]<0){
                    ++j;
                }else{
                    ans.push_back(vector{a,nums[j],nums[k]});
                    // find next uniq
                    --k;
                    while(k>0 && nums[k] == nums[k+1]){
                        --k;
                    }
                    ++j;
                    while(j<n-1 && nums[j] == nums[j-1]){
                        ++j;
                    }
                }
            }
        }
        return ans;
    }
};
