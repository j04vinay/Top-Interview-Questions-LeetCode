/* Longest Substring Without Repeating Characters
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        /* Method 1 : Optimize solution for this is use hashmap and keep track of last existence of that element 
        Time complexity for this will be O(n)
        We storing the starting and ending index of substrings 
        */
        int ans = 0, n= s.size(), start = 0;
        map<char, int> mp;
        for(int end=0; end<n; end++){
            if(mp.find(s[end])!=mp.end()){
                start = max(start, mp[s[end]]+1);
            }
            mp[s[end]] = end;
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};