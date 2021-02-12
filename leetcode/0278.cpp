class Solution {
public:
    int firstBadVersion(int n) {
        long int low = 0;
        long int high = n;
        while(low<high){
            long int mid = (low+high)/2;
            if(isBadVersion(mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};