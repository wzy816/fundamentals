/*
72. Edit Distance

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

// dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size();
        int w2 = word2.size();
        if(w1 == 0 || w2 == 0){
            return w1+w2;
        }
        
        int state[w1][w2];
        
        // fill top row and left column
        int i=0,j=0;
        if(word1.substr(0,1) == word2.substr(0,1)){
            state[0][0] = 0;
        }else{
            state[0][0] = 1;
        }
        for(j=1;j<w2;++j){
            if(word1.substr(i,1) == word2.substr(j,1)){
                state[i][j] = j;
            }else{
                state[i][j] = state[i][j-1]+1;
            }                
        }
        i=0;j=0;
        for(i=1;i<w1;++i){
            if(word1.substr(i,1) == word2.substr(j,1)){
                state[i][j] = i;
            }else{
                state[i][j] = state[i-1][j]+1;
            }                  
        }
        
        // fill rest row by row
        for(int i=1;i<w1;++i){
            for(int j=1;j<w2;++j){
                if(word1.substr(i,1)== word2.substr(j,1)) {
                    state[i][j] = min(min(state[i-1][j]+1, state[i][j-1]+1),state[i-1][j-1]);
                }else{
                    state[i][j] = min(min(state[i-1][j]+1, state[i][j-1]+1),state[i-1][j-1]+1);
                }
            }
        }        

        return state[w1-1][w2-1];
    }
};