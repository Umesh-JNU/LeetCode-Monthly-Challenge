class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> row_col;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    row_col.push_back({i, j});
                }
            }
        }
        
        for(auto rc : row_col){
            for(int c=0; c<matrix[0].size(); c++){
                matrix[rc[0]][c] = 0;
            }
            for(int r=0; r<matrix.size(); r++){
                matrix[r][rc[1]] = 0;
            }
        }
    }
};