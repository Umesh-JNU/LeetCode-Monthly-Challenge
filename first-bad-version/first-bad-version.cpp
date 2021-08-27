// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    #define ll long long
    int firstBadVersion(int n) {
        ll l = 0, r = n;
        int ans = 0;
        while(l <= r){
            ll mid = l + (r-l)/2;
            if(isBadVersion(mid)){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};