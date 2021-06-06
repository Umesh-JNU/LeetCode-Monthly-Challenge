class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // if n==1 whatever be nums[0] return true
        if(n == 1) return true;
        // if nums[0] == 0 and n > 1 (which is obvious from above)
        if(nums[0]==0) return false;
        
        int soFarFarthest = nums[0];
        for(int i=1; i<n-1; i++){
            soFarFarthest = max(soFarFarthest, i+nums[i]);
            
            if(i==soFarFarthest){
                return false;
            }
        }
        
        return true;
    }
};