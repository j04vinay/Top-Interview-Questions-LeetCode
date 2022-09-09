/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> pos;
        int m = matrix.size(), n = matrix[0].size();
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(matrix[i][j]==0){
//                     pos.push_back(i);
//                     pos.push_back(j);
//                 }
//             }
//         }
        
//         for(int i=0; i<pos.size();i++){
//             if(i%2==0){
//                 for(int j=0;j<n;j++){
//                     matrix[pos[i]][j] = 0;
//                 }
//             }else{
//                 for(int j=0;j<m;j++){
//                     matrix[j][pos[i]] = 0;
//                 }
//             }
//         }
        
        bool row = false, col = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                if(matrix[i][j]==0 && i==0) row = true;
                if(matrix[i][j]==0 && j==0) col = true;
             }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
             }
        }
        if(row){
            for(int i=0;i<n;i++) matrix[0][i] = 0;
        }
        if(col){
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        }
    }
};