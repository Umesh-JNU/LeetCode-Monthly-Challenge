class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return true;
        
        int g = 0;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                if(g >= 1) return false;
                g++;

                if(i < 2 ||nums[i-2] <= nums[i]){
                    nums[i-1] = nums[i];
                }else{
                    nums[i] = nums[i-1];
                }
            }
        }
        return true;
    }
};