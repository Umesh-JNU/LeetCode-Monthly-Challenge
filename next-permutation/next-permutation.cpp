class Solution {
public:
    void nextPermutation(vector<int>& perm) {
        int N = perm.size();
        // step 1 :- find 1st peak value from last
        int e = N - 1;
        while(e > 0 && perm[e] <= perm[e-1])
            e--;

        // if permutation is like 3 2 1, 4 3 2 1 etc then simply sort it 
        if(e == 0){
            sort(perm.begin(), perm.end());
            return;
        }

        /* step 2 :- find 1st greater value for perm[e-1]
         * 1 5 4 3 2, e = 1 
         * then swap 1 and 2
         */
        int idx = e;
        while (idx+1 < N && perm[e-1] < perm[idx+1])
            idx++;

        // swap
        int t = perm[idx];
        perm[idx] = perm[e - 1];
        perm[e - 1] = t;

        // step :- reverse from peak point
        reverse(perm.begin() + e, perm.end());
        return;
    }
};