class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

//         for (int i = 1; i <= amount; i++)
//             dp[0][i] = INT_MAX;

//         for(int i=1; i<=n; i++){
//             for(int j=1; j<=amount; j++){
//                 if(coins[i-1] > j)
//                     dp[i][j] = dp[i-1][j];
//                 else
//                     dp[i][j] = min(dp[i-1][j], (dp[i][j-coins[i-1]]!=INT_MAX ? dp[i][j-coins[i-1]]+1 : INT_MAX));
//             }
//         }
        // return dp[n][amount]==INT_MAX ? -1 : dp[n][amount];
        
        
        vector<double> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++){
            for(auto coin: coins){
                if(coin <= i)
                    dp[i] = min(dp[i], dp[i - coin]+1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};