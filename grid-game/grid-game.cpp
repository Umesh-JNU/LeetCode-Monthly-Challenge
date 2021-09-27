class Solution {
public:
    #define ll long long

    long long gridGame(vector<vector<int>> &grid) {
        int n = grid[0].size();
        vector<vector<ll>> dp(2, vector<ll>(n, 0));

        dp[0][n - 1] = grid[0][n - 1];
        for (int i = n - 2; i >= 0; i--)
            dp[0][i] = grid[0][i] + dp[0][i + 1];
        // display(vector<ll>(dp[0].begin(), dp[0].end()));

        dp[1][0] = grid[1][0];
        for (int i = 1; i < n; i++)
            dp[1][i] = grid[1][i] + dp[1][i - 1];
        // display(vector<ll>(dp[1].begin(), dp[1].end()));

        int i = 0;
        while (i + 1 < n && dp[0][i + 1] > dp[1][i])
            i++;

        // cout << "n = " << i << endl;
        if (i == n - 1)
            return dp[1][i - 1];
        if (i == 0)
            return dp[0][1];

        return max(dp[0][i + 1], dp[1][i - 1]);
    }
};