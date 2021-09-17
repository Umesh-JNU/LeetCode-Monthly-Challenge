class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int i = -1, j = 0, n = nums.size();
        double ans = INT_MIN;
        // cout << ans <<endl;
        while (j<n)
        {
            if(j-i != k)
                nums[j] += j == 0 ? 0 : nums[j - 1];
            else{
                nums[j] += (j == 0 ? 0 : nums[j - 1]);
                ans = max(ans, (double)(nums[j]-(i == -1 ? 0 : nums[i])) / (double)k);
                i++;
            }
            // cout << nums[j] << "     ";
            j++;
        }
        return ans;
    }
};