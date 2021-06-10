class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        multiset<int, greater<int>> s;
        s.insert(nums[0]);
        for (int i = 1; i < n; i++){
            dp[i] = *s.begin() + nums[i];

            if(i >= k){
                s.erase(s.find(dp[i-k]));
            }

            s.insert(dp[i]);
        }
        return dp[n - 1];
    }
};