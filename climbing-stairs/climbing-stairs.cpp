class Solution {
public:
    int utils(int n, vector<int> &dp){
        if(n <= 1 || dp[n] != -1) return dp[n];
        return dp[n] = utils(n-1, dp) + utils(n-2, dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1, dp[1] = 1;
        return utils(n, dp);
    }
};