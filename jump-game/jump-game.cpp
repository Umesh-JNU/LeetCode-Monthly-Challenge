class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        if(nums[0]==0) return false;
        
        int msf=nums[0];
        for(int i=1; i<n-1; i++){
            msf = max(msf, i+nums[i]);
            
            if(i == msf)
                return false;
        }
        return true;
    }
};