class Solution {
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long count = 0, reach = 0, i = 0;
        while (reach < n)
        {
            if(i >= nums.size()){
                reach += (reach+1);
                count++;
            }
            else{
                if(nums[i] <= reach+1){
                    reach += nums[i];
                    i++;
                }
                else{
                    reach += (reach + 1);
                    count++;
                }
            }
        }
        return count;
    }
};