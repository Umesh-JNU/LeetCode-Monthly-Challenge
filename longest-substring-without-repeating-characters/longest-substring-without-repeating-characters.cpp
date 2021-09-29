class Solution {
public:
    int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    if (n == 0)
        return 0;
    unordered_map<char, int> mp;
    int l = 0, ans = 0;
    for(int r=0; r<n; r++){
        if (mp.find(s[r]) != mp.end() && l <= mp[s[r]])
            l = mp[s[r]] + 1;

        mp[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}
};