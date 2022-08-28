/*Implement the myAtoi(string s) function, which converts a string to a 
32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) 
is '-' or '+'. Read this character in if it is either. This determines 
if the final result is negative or positive respectively. Assume the 
result is positive if neither is present.
Read in next the characters until the next non-digit character or the 
end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 
If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], 
then clamp the integer so that it remains in the range. Specifically, 
integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
*/


class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, base = 0, i = 0;
     
        // if whitespaces then ignore.
        while (s[i] == ' ')
        {
            i++;
        }

        // sign of number
        if (s[i] == '-' || s[i] == '+')
        {
            sign = 1 - 2 * (s[i++] == '-');
        }

        // checking for valid input
        while (s[i] >= '0' && s[i] <= '9')
        {
            // handling overflow test case
            if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            base = 10 * base + (s[i++] - '0');
        }
        return base * sign;
    }
};