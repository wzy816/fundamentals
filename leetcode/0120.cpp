/*
120. Triangle

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

// dp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        
        int state[row][col];
        
        // copy last
        for(int i=0;i<col;++i){
            state[row-1][i] = triangle[row-1][i];
        }
            
        // fill upwards
        for(int j=row-2;j>=0;--j){
            int total = triangle[j].size();
            for(int k = 0;k<total;++k){
                state[j][k] = min(triangle[j][k]+ state[j+1][k], triangle[j][k]+state[j+1][k+1]);
            }
        }
        
        // for(int i=0;i<row;++i){
        //     for(int j=0;j<col;++j){
        //         cout << state[i][j] << ',';
        //     }
        //     cout << endl;
        // }
        return state[0][0];
    
    }
};