/* Implement strStr().

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = needle.length(), n = haystack.length(), ans = -1;
        if(len==0)
            return 0;
        
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                if(haystack.substr(i, len)==needle)
                    return i;
            }
        }
        return ans;
        // return haystack.find(needle);
    }
};