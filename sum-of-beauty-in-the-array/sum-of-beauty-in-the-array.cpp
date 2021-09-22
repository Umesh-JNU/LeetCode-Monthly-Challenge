class Solution {
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> soFarMax(n), nextMin(n);
        soFarMax[1] = nums[0];
        nextMin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            soFarMax[i] = max(soFarMax[i - 1], nums[i - 1]);
            // cout << n-i-1 << " " << nextMin[n - i] << " " << nums[n-i] << endl;
            nextMin[n - i - 1] = min(nextMin[n - i], nums[n - i]);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            // cout << i << " " << ans << endl;
            if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                ans++;
                if(nums[i] > soFarMax[i] && nums[i] < nextMin[i])
                    ans++;
            }
        }
        return ans;
    }
};