/* Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size(), col = matrix[0].size();
        // initialize the possible direction 
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        // defining an vector to keep track of visited elements initializing visited as false
        vector<vector<bool> > isVisited(row, vector<bool>(col, false));
        // initially we are at (0,0) location 
        int r = 0, c = 0, di = 0;
        //travesing each element and storing it in ans 
        for(int i=0;i<row*col;i++){
            ans.push_back(matrix[r][c]);
            isVisited[r][c] = true;
            int newR = r + dr[di];
            int newC = c + dc[di];
            // if new coordinate is not out of bound and also not visited
            if(newR>=0 && newR<row && newC>=0 && newC<col && !isVisited[newR][newC]){
                r = newR;
                c = newC;
            }else{
                di = (di+1)%4;
                r = r + dr[di];
                c = c + dc[di];
            }
        }
        return ans;
    }
};