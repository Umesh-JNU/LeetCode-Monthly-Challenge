class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int N = fb.size(), i=0, count=0;
        while(i < N){
            if(fb[i]==0 && (i==0 || fb[i-1]==0) && (i==N-1 || fb[i+1]==0)){
                count++;
                fb[i] = 1;
            }
            if(count >= n) return true;
            i++;
        }
        return false;
    }
};