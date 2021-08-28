class Solution {
public:
//     set<vector<int>> ans;
//     void utils(vector<int> candidates, vector<int> &arr, int target, int idx){
//         if(idx == candidates.size()){
//             if(target == 0){
//                 vector<int> temp = arr;
//                 sort(temp.begin(), temp.end());
//                 ans.insert(temp);
//             }
//             return;
//         }

//         // pick
//         arr.push_back(candidates[idx]);
//         utils(candidates, arr, target - candidates[idx], idx + 1);
//         arr.pop_back();

//         utils(candidates, arr, target, idx + 1);
//     }
//     vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
//     {
//         vector<int> vec;
//         utils(candidates, vec, target, 0);
//         vector<vector<int>> t(ans.begin(), ans.end());
//         return t;
//     }
    vector<vector<int>> sol;
    void helper(vector<int> &candidates, vector<int> &arr, int target, int idx)
    {
        if (target == 0)
        {
            sol.push_back(arr);
            return;
        }
        if (idx == candidates.size())
        {
            return;
        }

        for (int i = idx; i < candidates.size(); i++)
        {
            if(target - candidates[i] < 0)return;
            if (i != idx && candidates[i] == candidates[i - 1])
                continue;

            arr.push_back(candidates[i]);
            helper(candidates, arr, target - candidates[i], i + 1);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        helper(candidates, vec, target, 0);
        return sol;
    }
};