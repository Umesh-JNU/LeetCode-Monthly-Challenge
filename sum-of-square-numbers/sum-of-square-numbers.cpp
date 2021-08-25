class Solution {
public:
    #define ll long long int
    bool judgeSquareSum(int c) {
        ll l = 0;
        ll r = sqrt(c);
        while (l <= r)
        {
            ll s = l * l + r * r;
            if(s > c)
                r--;
            else if(s < c)
                l++;
            else
                return true;
        }
        return false;
    }
};