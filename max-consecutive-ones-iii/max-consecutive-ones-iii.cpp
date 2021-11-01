class Solution {
public:
    int longestOnes(vector<int> &A, int B){
        int n = A.size();
        int l = 0, r = 0;
        int s = 0, e = 0;
        int zeroCount = 0;
        while(r < n){
            if(zeroCount <= B){
                if(A[r] == 0)
                    zeroCount++;
                r++;
            }
            if(zeroCount > B){
                if(A[l] == 0)
                    zeroCount--;
                l++;
            }
            if(e-s < r-l){
                s = l;
                e = r;
            }
        }
        return e - s;
    }
};