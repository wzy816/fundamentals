/*
424. Longest Repeating Character Replacement

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

// sliding window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0, mostLetters = 0;
        int count[26] = {0};
        int ans = -1;

        while(j < n)
        {
            count[s[j]-'A']++;

            // window length minus most letter count 
            // is the mininum edit need
            mostLetters = max(mostLetters, count[s[j]-'A']);
            if((j-i+1) - mostLetters > k){
                count[s[i]-'A']--;
                i++;
             }
            
            // current window is not always optimal
            // only meaningful when i dont increase above
            ans = max(ans, (j-i+1));

            j++;   
        }
        return ans;
    }
};