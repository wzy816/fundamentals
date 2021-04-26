/*
743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

*/

// dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<vector<int>>> edges;
        int delay[n+1];
        queue<int> q;      
        
        // init
        fill(delay, delay+n+1, INT_MAX);
        for(int i=1;i<=n;++i){
            edges[i] = vector<vector<int>>{};
        }
        
        for(vector<int> time : times){
            edges[time[0]].push_back(vector<int>{time[1],time[2]});
        }       
        
        // init start node
        q.push(k);
        delay[k] = 0;
        
        while(q.size() > 0){
            for(int i=q.size();i>0;--i){
                int cur = q.front();
                q.pop();
                for(vector<int> w : edges[cur]){
                    int n = w[0];
                    int weight = w[1];
                    if(delay[cur]+ weight < delay[n]){
                        delay[n] = delay[cur]+ weight;
                        // revisite node if weight is updated
                        q.push(n);
                    }
                }
            }
        }
        
        // find min;
        int ans = 0;
        for(int i=1;i<=n;++i){
            if(delay[i] == INT_MAX){
                return -1;
            }else{
                ans = max(ans, delay[i]);
            }
        }
        return ans;

    }
};