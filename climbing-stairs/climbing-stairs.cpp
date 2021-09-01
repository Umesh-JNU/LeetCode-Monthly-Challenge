class Solution {
public:
    int f(int n, vector<int> &dp){
        return (n <= 1 || dp[n] != -1) ? dp[n] : (dp[n] = (f(n-1, dp) + f(n-2, dp)));
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1, dp[1] = 1;
        return f(n, dp);
    }
};