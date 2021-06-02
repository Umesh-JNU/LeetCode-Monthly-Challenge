class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j){
        if(i < 0 || j < 0 || i == grid.size() || j==grid[0].size() || grid[i][j]<=0)
            return 0;

        grid[i][j] = -1;
        return 1 + dfs(grid, i - 1, j) +     // top
                   dfs(grid, i, j - 1) +     // left
                   dfs(grid, i + 1, j) +     // bottom
                   dfs(grid, i, j + 1);      // right
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        // base condition
        if(row == 0)
            return 0;
        int col = grid[0].size();
        int ans = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if(grid[i][j]==1){
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};