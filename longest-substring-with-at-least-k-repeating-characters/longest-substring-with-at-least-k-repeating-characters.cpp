class Solution {
public:
    int longestSubstring(string s, int k)
    {
        // cout << s << endl;
        int n = s.size();
        if (k > n)
            return 0;

        vector<int> freq(26, 0);
        for (auto c : s)
            freq[c - 'a']++;

        int start = 0, ans = 0;
        bool flag = true;
        for (int end = 0; end < n; end++)
        {
            int c = s[end] - 'a';
            if (freq[c] > 0 && freq[c] < k)
            {
                int x = longestSubstring(s.substr(start, end - start), k);
                // cout << x << " " << s.substr(start, end - start) << endl;
                ans = max(ans, x);
                start = end + 1;
                flag = false;
            }
        }
        return flag ? s.length() : max(ans, longestSubstring(s.substr(start), k));
    }
};