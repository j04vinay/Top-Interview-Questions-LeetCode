/* Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i=0;i<n;i++){
            int start = intervals[i][0], end = intervals[i][1];
            while(i<n-1 && end>=intervals[i+1][0]){
                end = max(intervals[i+1][1], end);
                i++;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};