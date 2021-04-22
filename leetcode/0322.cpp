/*
322. Coin Change

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int state[amount+1];
        fill(state, state+amount+1, 10000);
        state[0] = 0;
        
        for(int i=0;i<amount+1;i++){
            for(int j=0;j<coins.size();++j){
                int coin = coins[j];
                if(i == coin){
                    state[i] = 1;
                }else if( i > coin && state[i-coin]+1 < state[i]){
                    state[i] = state[i-coin]+1;
                }
            }
        }
        
        // for(int i=0;i<amount+1;++i){
        //     cout << state[i] << ',';
        // }
        
        return state[amount] == 10000? -1 :state[amount] ;
    }
};