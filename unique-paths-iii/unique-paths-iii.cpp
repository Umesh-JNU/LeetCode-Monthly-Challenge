class Solution {
public:
    int dfs(vector<vector<int>> &grid, int y, int x, int zeros){
        if(y < 0 || y >= grid.size() || x < 0 || x >= grid[0].size() || grid[y][x] == -1)
            return 0;
        if(grid[y][x] == 2)
            return zeros == -1 ? 1 : 0;

        grid[y][x] = -1;
        int total = dfs(grid, y - 1, x, zeros - 1) + dfs(grid, y + 1, x, zeros - 1) + dfs(grid, y, x - 1, zeros - 1) + dfs(grid, y, x + 1, zeros - 1);
        grid[y][x] = 0;
        return total;
    }
    int uniquePathsIII(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // finding the start and the end and counting the number of zeros
        int sx = 0, sy = 0, zeros = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                    sy = i, sx = j;
                if(grid[i][j] == 0)
                    zeros++;
            }
        }

        return dfs(grid, sy, sx, zeros);
    } 
};