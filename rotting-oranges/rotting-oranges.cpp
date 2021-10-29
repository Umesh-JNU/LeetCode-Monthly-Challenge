class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = -1, fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> cp = q.front();
                q.pop();

                // top
                if (cp.first - 1 >= 0 && grid[cp.first - 1][cp.second] == 1)
                {
                    grid[cp.first - 1][cp.second] = 2;
                    q.push(make_pair(cp.first - 1, cp.second));
                    fresh--;
                }
                // left
                if (cp.second - 1 >= 0 && grid[cp.first][cp.second - 1] == 1)
                {
                    grid[cp.first][cp.second - 1] = 2;
                    q.push(make_pair(cp.first, cp.second - 1));
                    fresh--;
                }
                // bottom
                if (cp.first + 1 < n && grid[cp.first + 1][cp.second] == 1)
                {
                    grid[cp.first + 1][cp.second] = 2;
                    q.push(make_pair(cp.first + 1, cp.second));
                    fresh--;
                }
                // right
                if (cp.second + 1 < m && grid[cp.first][cp.second + 1] == 1)
                {
                    grid[cp.first][cp.second + 1] = 2;
                    q.push(make_pair(cp.first, cp.second + 1));
                    fresh--;
                }
            }
            ans++;
        }
        if(fresh > 0)
            return -1;
        if(ans == -1)
            return 0;
        return ans;
    }
};