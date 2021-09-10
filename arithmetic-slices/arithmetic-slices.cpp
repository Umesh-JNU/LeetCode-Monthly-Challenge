class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return 0;
        int ans = 0;
        int start = 0;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] != nums[i - 1] - nums[i - 2])
            {
                if (i != 2)
                    ans += ((i - start - 2) * (i - start - 1)) / 2;
                start = i - 1;
            }
            else
            {
                if (i == n - 1)
                    ans += ((i - start - 1) * (i - start)) / 2;
            }
        }
        return ans;
    }
};