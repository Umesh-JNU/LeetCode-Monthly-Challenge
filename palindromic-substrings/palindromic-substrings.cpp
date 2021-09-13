class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            dp[i][i] = 1;
            if(i < n-1 && s[i] == s[i+1])
                dp[i][i + 1] = 1;
        }

        for (int d = 2; d < n; d++)
        {
            for (int j = 0; j < n-d; j++)
            {
                if (s[j] == s[j+d] && dp[j+1][j + d - 1])
                    dp[j][j+d] = 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
                ans += dp[i][j];
        }
        return ans;
    }
};