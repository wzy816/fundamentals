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