class Solution {
public:
    int arrangeCoins(int n) {
        int l=0, h=n, k=1;
        long long mid;
        while(l <= h){
            mid = l + (h-l)/2;
            long long t = (mid*(mid+1))/2;
            if(t == n){
                return mid;    
            }
            else if(t > n)
                h = mid-1;
            else
                l = mid+1;
        }
        return h;
    }
};