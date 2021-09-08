class Solution {
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int sum = 0;
        for(auto e: nums)
            sum += e;

        int left = 0;
        for (int i = 0; i < nums.size(); i++){
            if(left == sum-nums[i]){
                return i;
            }
            sum -= nums[i];
            left += nums[i];
        }
        return -1;
    }
};