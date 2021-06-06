class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || nums[0]==0) return 0;
        
        int jump = 1;
        int soFarFarthest = nums[0];
        int currEnd = nums[0];
        for(int i=1; i<n-1; i++){
            soFarFarthest = max(soFarFarthest, i+nums[i]);
            
            if(i == currEnd){
                currEnd = soFarFarthest;
                jump++;
            }
        }
        
        return jump;
    }
};