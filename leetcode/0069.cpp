class Solution {
public:
    int mySqrt(int x) {
        if(x <=1){
            return x;
        }
        int low = 0;
        int high = x;
        while(low < high){
            long int mid = (low+high)/2;
            if(mid*mid > x){
                high = mid;
            }else if(mid * mid == x){
                return mid;
            }else{
                low = mid+1;
            }
        }
        return low-1;
    }
};