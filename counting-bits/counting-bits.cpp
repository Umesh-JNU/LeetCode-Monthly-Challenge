class Solution {
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        ans[0] = 0;

        int j = 0;
        for (int i = 1; i <= n; i++)
        {
            ans[i] = 1 + ans[i - (1 << j)];
            if (i+1 == (1 << (j+1)))
                j++;
        }
        return ans;
    }
};