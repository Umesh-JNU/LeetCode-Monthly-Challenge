class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if(n < 0 || (n != 1 && n&1))
            return false;
        for (int i = 0; i <= 31; i++) if(1 << i == n)
            return true;
        return false;
    }
};