/*
1201. Ugly Number III
Given four integers n, a, b, and c, return the nth ugly number.

Ugly numbers are positive integers that are divisible by a, b, or c.


Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.


Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.


Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.


Example 4:

Input: n = 1000000000, a = 2, b = 217983653, c = 336916467
Output: 1999999984
 

Constraints:

1 <= n, a, b, c <= 109
1 <= a * b * c <= 1018
It is guaranteed that the result will be in range [1, 2 * 109].
 
*/

#define ll long long

class Solution {
public:
    // 最大公约数
    int gcd(int x,int y){
        return y>0?gcd(y,x%y):x;
    }
        
    int nthUglyNumber(int n, int a, int b, int c) {
        ll low = 1;
        ll high = 2 * pow(10, 9);
        
        // 最小公倍数 = 乘积/最大公约数
        ll ab = ((ll)a*b) / gcd(a,b);
        ll bc = ((ll)b*c) / gcd(b,c);
        ll ca = ((ll)c*a) / gcd(c,a);
        ll abc = ((ll)c*ab) / gcd(c,ab);

        while(low < high){
            ll mid = ((ll)(low+high)) /2;
            
            // count total by vein 
            int t1 = mid/a+mid/b+mid/c;
            int t2 = mid/ab+mid/bc+mid/ca;
            int t3 = mid/abc;
            int total = t1-t2+t3;

            if( total >= n){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return (int)low;
    }
};