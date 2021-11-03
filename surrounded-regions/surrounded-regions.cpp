class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        board[i][j] = 'Y';
        for (auto p : dir)
        {
            int y = i + p[0];
            int x = j + p[1];
            if (y >= 0 && y < board.size() && x >= 0 && x < board[0].size() && board[y][x] == 'O')
                dfs(board, y, x);
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        // 1st row and last row
        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O')
                dfs(board, 0, i);
            if (board[n - 1][i] == 'O')
                dfs(board, n - 1, i);
        }

        // 1st column and last column
        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1);
        }

        // now changing the remaining 'O' - 'X' and 'Y' - 'O'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
        return;
    }
};
/*


*/