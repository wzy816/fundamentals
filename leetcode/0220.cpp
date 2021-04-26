/*
220. Contains Duplicate III

Given an integer array nums and two integers k and t, return true if there are two distinct indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if(n <= 1 || k <=0){
            return false;
        }

        // use multiset to maintain a window of k elements
        // init with first k elements
        multiset<long long> w;
        int j = 0;
        while(j< k && j < n-1){
            w.insert(nums[j]);
            ++jop;
        }
        
        // 
        int i = 0;
        while(i < n){
            long long num = nums[i];
            w.erase(w.equal_range(num).first);

            // insert if not reaching end
            if(j < n){
                w.insert(nums[j]);
                ++j;
            }

            // check if value btw [nums[j]-t, nums[j]+t] exists
            auto search = w.lower_bound(num-t);
            if(search != w.end() && *search <= num +t){
                return true;
            }
            ++i;
        }
        return false;
    }
};