/*
904. Fruit Into Baskets
Medium

In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.

You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.

What is the total amount of fruit you can collect with this procedure?

*/

// sliding window

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int ans = 0;
        int i=0,j=0;
        int count[40000] = {0};
        int uniq=0;
        for(;i<tree.size();++i){
            while(j<tree.size()){
                if(uniq == 2 && count[tree[j]] == 0){
                    break;
                }
                if(count[tree[j]] ==0){
                    uniq++;
                }
                count[tree[j]]++;
                ++j;
            }
            
            ans = max(ans, j-i);
            
            count[tree[i]]--;
            if(count[tree[i]] == 0){
                uniq--;
            }
        }
        return ans;
    }
};