class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mh = 0;
        int msf = nums[0];
        for(int i=0; i<nums.size(); i++){
            mh += nums[i];
            msf = max(msf, mh);
            if(mh < 0) mh = 0;
        }
        return msf;
    }
};