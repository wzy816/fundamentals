/*
207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/

// topo sort using dfs
class Solution {
public:
    unordered_map<int, vector<int>> dep;
    bool ans;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ans = true;
        // build reverse adj-list
        for(vector<int> pre: prerequisites){
            
            if(dep.find(pre[0]) != dep.end()){
                dep[pre[0]].push_back(pre[1]);
            }else{
                dep[pre[0]] = vector<int>{pre[1]};
            }
        }

        // dfs check loop
        for(int cur= 0;cur< numCourses; ++cur){
            int visited[100000] = {0};
            dfs(cur, visited, cur);
            if(!ans) return false;
        }
        return ans;
    }
    void dfs(int cur, int visited[100000], int root){
        if(!ans) return;
        if(cur< root) return;
       
        for(int d: dep[cur]){
            if(d == root){
                ans = false;
                return;
            }
            if(visited[d] == 0){
                visited[cur] = 1;
                dfs(d, visited, root);
            }
            
        }
    }
};

// kahn
class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> dep;
        unordered_map<int, int> indegree;
        
        // build reverse adj-list and indegree
        for(vector<int> p: prerequisites){
            int from = p[1];
            int to = p[0];
            if(indegree.find(from) == indegree.end()){
                indegree[from] = 0;
            }
            if(indegree.find(to) == indegree.end()){
                indegree[to] = 1;
            }else{
                indegree[to] ++;
            }
            dep[from].push_back(to);
        }
        
        // init q with all nodes of indegree zero
        queue<int> q;
        for(auto it: indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        
        while(q.size()>0){
            int cur = q.front();
            q.pop();
            indegree.erase(cur);
            
            // decrease child node indegree
            // if zero, push to queue
            for(int d : dep[cur]){
                indegree[d]--;
                if(indegree[d] == 0){
                    q.push(d);
                    indegree.erase(d);
                }
            }
        }
        
        return indegree.size() == 0;
    }
   
};