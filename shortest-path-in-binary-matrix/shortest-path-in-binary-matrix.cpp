class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;

        /**
         *  (-1, -1) ( -1, 0) (-1, 1)
         *  ( 0, -1)   [*]    ( 0, 1)
         *  ( 1, -1) ( 1,  0) ( 1, 1)
         */
        vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<vector<int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        vector<int> cur;
        while (!q.empty())
        {
            cur = q.front();
            q.pop();

            for (auto d : dir)
            {
                int i = d[0] + cur[0];
                int j = d[1] + cur[1];

                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 0)
                {
                    grid[i][j] = grid[cur[0]][cur[1]] + 1;
                    q.push({i,j});
                }
            }
        }
        return grid[m - 1][n - 1] ? grid[m - 1][n - 1] : -1;
    }
};