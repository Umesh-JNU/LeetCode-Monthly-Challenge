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
// optimized version
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cell1 = false;
        for(int i=0; i<matrix.size(); i++){
            if(matrix[i][0]==0){
                cell1 = true;
            }
            for(int j=1; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // columns
        for(int r=1; r<matrix.size(); r++){
            for(int c=1; c<matrix[0].size(); c++){
                if(matrix[0][c]==0 || matrix[r][0]==0){
                    matrix[r][c]=0;
                } 
            }
        }
        
        // first row
        if(matrix[0][0]==0){
            for(int c=0; c<matrix[0].size(); c++){
                matrix[0][c] = 0;
            }
        }
        if(cell1){
            for(int r=0; r<matrix.size(); r++){
                matrix[r][0]=0;
            }
        }
    }
};
