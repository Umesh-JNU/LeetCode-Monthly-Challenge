class Solution {
public:
    vector<vector<int>> ans;
    map<int, int> mp;
    void recur(vector<int> &nums, vector<int> temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = i;
                temp.push_back(nums[i]);
                recur(nums, temp);
                mp.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.size() == 0)
            return result;
        vector<int> temp;

        recur(nums, temp);
        return ans;
    }
};