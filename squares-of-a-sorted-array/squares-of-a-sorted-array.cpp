class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> ans(n);
        while (l <= r)
        {
            if (abs(nums[l]) > abs(nums[r]))
            {
                ans[n-1] = nums[l]*nums[l];
                l++;
            }
            else
            {
                ans[n-1] = nums[r]*nums[r];
                r--;
            }
            n--;
        }
        return ans;
    }
};