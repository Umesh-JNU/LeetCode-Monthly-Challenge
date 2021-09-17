class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m+1, 0);
        int ans = 0, temp, prev = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j<=m; j++){
                temp = dp[j];
                if(matrix[i-1][j-1]=='1'){
                    dp[j] = min(min(dp[j], dp[j - 1]), prev)+1;
                    ans = max(ans, dp[j]);
                }
                else
                    dp[j] = 0;
                prev = temp;
            }
        }
        return ans * ans;
    }
};