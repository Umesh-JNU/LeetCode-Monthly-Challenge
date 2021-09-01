class Solution {
public:
    int f(int n, vector<int> &dp){
        if(dp[n] != -1)return dp[n];
        if(n<=1)return n;
        
        return dp[n] = f(n-1, dp)+f(n-2, dp);
        
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        return f(n, dp);
        // return n <= 1 ? n : fib(n-1)+fib(n-2);
    }
};