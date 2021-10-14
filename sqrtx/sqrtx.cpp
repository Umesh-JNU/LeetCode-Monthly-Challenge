class Solution {
public:
    int mySqrt(int x)
    {
        if(x==0) 
            return 0;
        int l = 1, r = x;
        long long int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(mid*mid <= x && (mid+1)*(mid+1) > x)
                break;
            else if(mid*mid > x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return mid;
    }
};