/*
5. Longest Palindromic Substring
Medium

Given a string s, return the longest palindromic substring in s.
 
Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"
*/

class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int state[n][n];

        // iterate upper-right triangle
        int l= 0;
        string ans = "";
        for(int i=0;i<n;++i){
            for (int j=0;j<n-i;++j){
                int start = j;
                int end = i+j;
                if(start == end){
                    state[start][end] = 1;
                }else{
                    if(start+1 == end){
                        if(s[start] == s[end]){
                            state[start][end] = 1;
                        }else{
                            state[start][end] = 0;
                        }
                    }else{
                        if(s[start] != s[end]){
                            state[start][end] = 0;
                        }else{
                            state[start][end] = state[start+1][end-1];
                        }
                    }
                }
                if(state[start][end] == 1 && i+1 > l){
                    l = i+1;
                    ans = s.substr(start, end-start+1);
                }
            }
        }
        return ans;
    }

};