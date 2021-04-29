/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int i=0,j=0;
        unordered_map<char, int> count;
        for(;i<s.size();++i){
            while(j<s.size() && count[s[j]] == 0){
                count[s[j]] = 1;
                ++j;
            }
            ans = max(ans, j-i);
            count[s[i]] = 0;
        }
        return ans;
    }
};

 