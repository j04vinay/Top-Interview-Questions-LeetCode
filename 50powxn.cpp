/* Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        double t = myPow(x, n/2);
        if(n%2==0) return t*t;
        else{
            if(n>0) return t*t*x;
            else return t*t/x;
        }
    }
};