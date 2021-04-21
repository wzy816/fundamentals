/*
1143. Longest Common Subsequence

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
*/

// dp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        if(n1 == 0 || n2 == 0){
            return 0;
        }
        
        int state[n1][n2];
        
        // fill top and left
        if(text1.substr(0,1) == text2.substr(0,1)){
            state[0][0] = 1;
        }else{
            state[0][0] = 0;
        }
        for(int i=1;i<n2;++i){
            if(text1.substr(0,1) == text2.substr(i,1)){
                state[0][i] = 1;
            }else{
                state[0][i] = state[0][i-1];
            }
        }
        for(int i=1;i<n1;++i){
             if(text1.substr(i,1) == text2.substr(0,1)){
                state[i][0] = 1;
            }else{
                state[i][0] = state[i-1][0];
            }           
        }
        
        // fill rest
        for(int i=1;i<n1;++i){
            for(int j=1;j<n2;++j){
                 if(text1.substr(i,1) == text2.substr(j,1)){
                     state[i][j] = max(max(state[i-1][j-1]+1, state[i-1][j]), state[i][j-1]);
                 }else{
                     state[i][j] = max(max(state[i-1][j-1], state[i-1][j]), state[i][j-1]);
                 }
            }
        }
        
        return state[n1-1][n2-1];
    }
};