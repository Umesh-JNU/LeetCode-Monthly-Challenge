class Solution {
public:
    vector<vector<int>> ans;
    void utils(vector<int> candidates, vector<int> &arr, int idx, int target){
        // display(arr);
        if(target < 0 || idx >= candidates.size())
            return;
        if(target == 0){
            ans.push_back(arr);
            return;
        }

        // pick
        arr.push_back(candidates[idx]);
        utils(candidates, arr, idx, target-candidates[idx]);
        arr.pop_back();

        // not pick
        utils(candidates, arr, idx + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> t;
        utils(candidates, t, 0, target);
        return ans;
    }
};