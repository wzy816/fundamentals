/*
779. K-th Symbol in Grammar

Given row N and index K, return the K-th indexed symbol in row N. (The values of K are 1-indexed.) (1 indexed).

Examples:
Input: N = 1, K = 1
Output: 0

Input: N = 2, K = 1
Output: 0

Input: N = 2, K = 2
Output: 1

Input: N = 4, K = 5
Output: 1

Explanation:
row 1: 0
row 2: 01
row 3: 0110
row 4: 01101001
Note:

N will be an integer in the range [1, 30].
K will be an integer in the range [1, 2^(N-1)].
*/

class Solution {

public:
    int kthGrammar(int N, int K) {
        if(K == 0){
            return 1;
        }
        if(K == 1){
            return 0;
        }
        int p = kthGrammar(N-1, (K+1)/2);
        if(p == 1){
            if(K%2==1){
                return 1;
            }else{
                return 0;
            }
        }else{
            if(K%2==1){
                return 0;
            }else{
                return 1;
            }
        }
    }
};
