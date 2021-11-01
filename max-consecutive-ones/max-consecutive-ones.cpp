class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0, r=0, ans = 0;
        while(r < nums.size()){
            if(nums[r]==0){
                ans = max(ans, r-l);
                l = r+1;
            }
            r++;
        }
        return max(ans, r-l);
    }
};