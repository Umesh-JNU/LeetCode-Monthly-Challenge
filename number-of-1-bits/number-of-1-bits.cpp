class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0, i = 32;
        while (i--)
        {
            if (n & 1)
                ans++;
            n >>= 1;
        }
        return ans;
    }
};