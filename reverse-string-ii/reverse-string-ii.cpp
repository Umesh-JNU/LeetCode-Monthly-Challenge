class Solution {
public:
    void revUtils(string &s, int i, int j)
    {
        while (i <= j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k)
    {
        int n = s.size();
        int i, l, r;
        for (i = 0; i + (2 * k - 1) < n; i += 2 * k)
            revUtils(s, i, i + k - 1);
        revUtils(s, i, min(n - 1, i + k - 1));

        return s;
    }
};