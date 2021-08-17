class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n <= 1)
            return n;

        int ans = 0;
        map<int, int> freq;
        int l = 0, r = 0;
        while (r < n)
        {
            if (freq.find(s[r]) == freq.end())
            {
                freq[s[r]]++;
                r++;

                ans = max(ans, r - l);
            }
            else
            {
                do
                {
                    freq[s[l]]--;
                    if (freq[s[l]] == 0)
                        freq.erase(s[l]);
                    l++;
                } while (s[l - 1] != s[r]);
            }
        }
        return ans;
    }
};