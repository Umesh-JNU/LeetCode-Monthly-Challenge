class Solution {
public:
    int T(int n, vector<int> &dp){
        if(n <= 2 || dp[n] != -1) return dp[n];
        return dp[n] = T(n-1, dp) + T(n-2, dp) + T(n-3, dp); 
    }
    int tribonacci(int n) {
        vector<int> dp(n+3, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return T(n, dp);
    }
};