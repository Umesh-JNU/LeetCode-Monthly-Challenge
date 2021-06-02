class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    // check for top
                    if(i-1<0 || !grid[i-1][j]) peri++;
                    // check for left
                    if(j-1<0 || !grid[i][j-1]) peri++;
                    // check for bottom
                    if(i+1>=row || !grid[i+1][j]) peri++;
                    // check for right
                    if(j+1>=col || !grid[i][j+1]) peri++;
                }
            }
        }
        return peri;
    }
};