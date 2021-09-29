class Solution {
public:
    bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if(n1 > n2)
        return false;
    vector<int> mp(26,0);
    for(auto e: s1)
        mp[e-'a']++;

    vector<vector<int>> dp(n2, vector<int>(26, 0));
    
    for (int i = 0; i < n2; i++)
    {
        if(i > 0)
            dp[i] = dp[i - 1];
        dp[i][s2[i] - 'a']++;
        if(i >= n1-1){
            int c;
            for (c = 0; c < 26; c++){
                if(dp[i][c]-(i-n1 < 0 ? 0 : dp[i-n1][c]) != mp[c])
                    break;
            }
            if(c==26)
                return true;
        }
    }
    return false;
}
};