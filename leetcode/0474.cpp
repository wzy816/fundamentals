/*
474. Ones and Zeroes

You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.
*/

// use divide-and-conquer, not efficient
class Solution {
public:
    int ans;
    int findMaxForm(vector<string>& strs, int m, int n) {
        ans = 0;
        helper(strs, 0, m,n,0);
        return ans;
    }
    void helper(vector<string>& strs, int i, int m, int n, int total){
        if(i >= strs.size() || (m==0 && n==0)){
            if(total > ans){
                ans = total;
            }
            return;
        }
        // not use i
        helper(strs,i+1,m,n,total);
        // use i
        int m2=0;
        int n2=0;
        for(char ch : strs[i]){
            if(ch == '0'){
                m2++;
            }
            if(ch == '1'){
                n2++;
            }
        }
        if(m2 <= m && n2 <= n){
            helper(strs,i+1,m-m2, n-n2, total+1);
        }
    }
};

// dp
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> state;
        
        for(int i=0;i<strs.size();++i){
            
            // init state by copy from last
            // state represent 0-m * 0-n grid
            // cell value means selected set size
            vector<int> s((m+1)*(n+1),0);
            if(i > 0){
                s = vector<int>(state[i-1]);
            }
            
            // count 1 and 0 of current str
            int zero = 0;
            int one = 0;
            for(char ch : strs[i]){
                if(ch == '0'){
                    zero++;
                }
                if(ch == '1'){
                    one++;
                }
            }
            // use current str only
            if(zero<=m && one<=n && s[one*(m+1)+zero] == 0){
                s[one*(m+1)+zero] = 1;
            }
            // use current str over previous set
            for(int j =0;j<=m;++j){
                for(int k=0;k<=n;++k){
                    int index = k*(m+1)+j;
                    if(i > 0 && state[i-1][index] > 0){
                        if(j+zero <= m && k+one<= n){
                            int new_index = (k+one)*(m+1)+ (j+zero);
                            s[new_index] = max( s[new_index], state[i-1][index]+1);
                        }
                    }
                }
            }
            state.push_back(s);
        }
        
        // find max size from last state
        int ans = 0;
        for(int num: state[state.size()-1]){
            ans = max(ans,num);
        }
        return ans;
    }
};
