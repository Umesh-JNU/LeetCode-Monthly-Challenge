class Solution {
public:
    #define MOD 1000000007

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        matrix[startRow][startColumn] = 1;
        int ans = 0;
        for (int k = 1; k <= maxMove; k++){
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    int L = (j - 1 >= 0) ? matrix[i][j - 1] : 0;
                    int R = (j + 1 < n) ? matrix[i][j + 1] : 0;
                    int T = (i - 1 >= 0) ? matrix[i - 1][j] : 0;
                    int B = (i + 1 < m) ? matrix[i + 1][j] : 0;

                    dp[i][j] = (dp[i][j] + L) % MOD;
                    dp[i][j] = (dp[i][j] + R) % MOD;
                    dp[i][j] = (dp[i][j] + T) % MOD;
                    dp[i][j] = (dp[i][j] + B) % MOD;
                }
            }

            for (int i = 0; i<m; i++){
                ans = (ans + matrix[i][0]) % MOD;
                ans = (ans + matrix[i][n - 1]) % MOD;
            }

            for (int j = 0; j<n; j++){
                ans = (ans + matrix[0][j]) % MOD;
                ans = (ans + matrix[m-1][j]) % MOD;
            }

            swap(dp, matrix);
        }

        return ans;
    }
};