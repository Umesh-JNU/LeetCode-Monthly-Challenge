class Solution {
public:
    bool isPerfectSquare(int num)
    {
        int l = 1, r = num, mid;
        while(l <= r){
            mid = l+(r-l)/2;
            if((long long)mid*mid > num)
                r = mid - 1;
            else if((long long)mid*mid < num)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};