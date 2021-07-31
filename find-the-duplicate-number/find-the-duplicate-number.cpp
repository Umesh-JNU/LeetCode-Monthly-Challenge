class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans, idx;
        for (int i = 0; i < n;i++){
            idx = nums[i] < 0 ? -nums[i] - 1 : nums[i] - 1;
            if(nums[idx] < 0){
                ans = nums[i] < 0 ? -nums[i] : nums[i];
                break;
            }
            nums[idx] *= -1;
        }
        return ans;
    }
};