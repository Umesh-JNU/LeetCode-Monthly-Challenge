class Solution {
public:
    int method3(int n){
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++)
            dp[i] = i;

        for (int i = 4; i <= n; i++){
            for (int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
        return dp[n];
    }
    int numSquares(int n) {
        return method3(n);
    }
};