class Solution {
public:
    int climbStairs(int n) {
        int m = 2; // atmost 2 jump at each step
        int dp[n+1];
        dp[0]=1;
        int temp = 0;
        for(int i=1; i<=n; i++){
            int add_idx = i - 1;
            int rem_idx = i - m - 1;
            if(rem_idx >= 0){
                temp -= dp[rem_idx];
            }
            temp += dp[add_idx];
            dp[i] = temp;
        }
        
        return dp[n];
    }
};