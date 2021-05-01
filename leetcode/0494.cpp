/*
494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

// dp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0){
            return nums[0] == target? 1:0;
        }
        int sum[n][2000+1];
        memset(sum,0,sizeof(sum));
        
        sum[0][nums[0]+1000]++;
        sum[0][-nums[0]+1000]++;
        
        for(int i=1;i<nums.size();++i){

            for(int j=0;j<2001;++j){
                int lastSum = sum[i-1][j];
                if( lastSum != 0){
                    sum[i][j+nums[i]] += lastSum;
                    sum[i][j-nums[i]] += lastSum;
                }
            }
        }
        return sum[n-1][target+1000];
    }
};