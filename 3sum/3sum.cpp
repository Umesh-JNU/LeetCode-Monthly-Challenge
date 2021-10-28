class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if(n < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n-2; i++){
            // skipping the duplicates value for A and when A > 0
            if(nums[i] > 0)
                break;
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i + 1, high = n - 1;
                while(low < high){
                    int s = nums[low] + nums[high];
                    if(s > -nums[i]){
                        high--;
                    }
                    else if(s < -nums[i]){
                        low++;
                    }else{
                        ans.push_back({nums[i], nums[low], nums[high]});

                        while(low < high && nums[low] == nums[low+1])
                            low++;
                        while(low < high && nums[high] == nums[high-1])
                            high--;

                        // for setting different value
                        low++;
                        high--;
                    }
                }
            }
        }
        return ans;
    }
};