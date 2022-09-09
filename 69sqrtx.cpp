/* Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

Example 1:
Input: x = 4
Output: 2
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        //end element as "x" as no square root increases the element itself
        int start = 1, end = x;
        while(1){
            int mid = start + (end - start)/2;
			
			//Take an example and follow it in your book. It's really interesting!
            if (mid > x/mid) end = mid - 1;
            else {
                if (mid + 1 > x/(mid + 1)) return mid;
                start = mid + 1;
            }
        }
    }
};