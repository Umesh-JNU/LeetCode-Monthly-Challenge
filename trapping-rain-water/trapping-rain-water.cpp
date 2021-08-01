class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n <= 2){
            return 0;
        }

        vector<int> dp(n);
        dp[0] = h[0];
        for (int i = 1; i < n; i++){
            dp[i] = max(dp[i - 1], h[i]);
        }
        dp[n - 1] = min(dp[n - 1], h[n - 1]);
        for (int i = n - 2; i >= 0;i--){
            dp[i] = min(dp[i], max(dp[i + 1], h[i]));
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += dp[i] - h[i];

        return ans;
    }
};