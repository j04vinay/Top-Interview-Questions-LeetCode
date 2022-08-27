/* Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer 
range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers 
(signed or unsigned).

Example 1:
Input: x = 123
Output: 321
*/


class Solution {
public:
    int reverse(int x) {
        /* This is the one and only solution 
        INT_MAX is equal 2147483647. INT_MIN is equal  -2147483648. 
        So we have to check for given coditions 
        */
        
        int ans = 0, lastans = 0, t = abs(x);
        while(t){
            int rem = t % 10;
            if(ans > INT_MAX/10 || ans == INT_MAX/10 && rem > 7){
                return 0 ;
            }
            if(ans < INT_MIN/10 || ans == INT_MIN/10 && rem < -8){
                return 0 ;
            }
            ans = ans*10 + rem;
            t = t/10;
        }
        if(x<0)
            ans = -ans;
        
        return ans;
    }
};