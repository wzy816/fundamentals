/*
395. Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.
*/

// sliding window

class Solution
{
public:
    int longestSubstring(string s, int k) {
        int letterCount[26];
        for(char c: s){
            letterCount[c-'a'] += 1;
        }
        int maxUniqLetters = 0;
        for(int i=0;i<26;++i){
            if(letterCount[i]>=k){
                maxUniqLetters ++;
            }
        }
        
        int ans = 0;
        
        // limit uniq letters in each window
        // so that sliding is feasible
        
        for(int uniq=1; uniq<=maxUniqLetters; ++uniq){
            int start=0, end=0, curUniq=0, curKMore=0;
            int count[26] = {0};
            while(end <= s.size()-1){
                if(curUniq <= uniq){
                    // expand
                    if(count[s[end]-'a'] == 0) curUniq++;
                    count[s[end]-'a']++;
                    if(count[s[end]-'a'] == k) curKMore++;
                    end++;
                }else{
                    // shrink
                    if(count[s[start]-'a'] == k) curKMore--;
                    count[s[start]-'a']--;
                    if(count[s[start]-'a'] == 0) curUniq--;
                    start++;
                }
                // check validity
                if(curUniq == uniq and curKMore == uniq){
                    ans = max(ans, end-start);
                }
            }
        }

        return ans;
    }
};