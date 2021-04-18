/*
347. Top K Frequent Elements

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto iter=m.begin(); iter!=m.end(); ++iter){
            pq.push(make_pair(iter->second, iter->first));
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ret;
        while(k--){
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};
