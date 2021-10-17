class Solution {
public:
    // mutable array
    /*
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
    */
    int findDuplicate(vector<int> &nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        fast = nums[0];
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};