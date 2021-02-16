/*509. Fibonacci Number
*/

class Solution {
public:
    int fib(int n) {
        if(n == 0){
            return  0;
        }
        if(n == 1){
            return 1;
        }
        vector<int> ret{0,1};
        for(int i=1;i<n;i++){
            ret.push_back(ret[i-1]+ret[i]);    
        }
        return ret.back();
    }
};