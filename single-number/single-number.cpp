class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=0;
        for(auto e: nums)
            n ^= e;
        return n;
    }
};