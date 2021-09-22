class Solution {
public:
    #define ui unsigned int
    int numDistinct(string s, string t) {
        // return 0;
        int n=t.size(), m=s.size();
        vector<vector<ui>> dp(n+1, vector<ui>(m+1, 0));
        for(int i=0; i<=m; i++)dp[0][i]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(t[i-1]==s[j-1]){
                    dp[i][j] = dp[i-1][j-1]+dp[i][j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};