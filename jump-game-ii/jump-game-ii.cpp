class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        
        int msf = nums[0], max_cur=nums[0], ans=1;
        for(int i=1; i<n-1; i++){
            max_cur = max(max_cur, i+nums[i]);
            if(i == msf){
                ans++;
                msf = max_cur;
            }
        }
        return ans;
    }
};