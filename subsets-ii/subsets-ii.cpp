class Solution {
public:
    vector<vector<int>> ans;
    void utils(vector<int> nums, vector<int> &arr, int idx){
        ans.push_back(arr);
        for (int i = idx; i < nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1])
                continue;
            arr.push_back(nums[i]);
            utils(nums, arr, i + 1);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a;
        utils(nums, a, 0);
        return ans;
    }
};