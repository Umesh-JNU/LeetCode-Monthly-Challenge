class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n <= 1)
            return n;

        unordered_map<char, int> mp;
        int l = 0, r = 0, ans = 0;
        while (r < n)
        {   
            //    0 1 2 3 4 5 6 7 8 9
            // if a b c a a b c d b e 
            //            l r
            // mp[b] = 1
            // Here we will not increase `` l `` pointer as l > 1 ie. start pointer is pointing to another substring 
            if (mp.find(s[r]) != mp.end() && l <= mp[s[r]])
            {
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;
            r++;
            ans = max(ans, r - l);
        }
        return ans;
    }
};