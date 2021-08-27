class Solution {
public:
    vector<vector<int>> ans;
    void utils(int n, int k, vector<int> &arr, int idx){
        if(arr.size() == k){
            ans.push_back(arr);
            return;
        }
        for (int i = idx; i <= n; i++){
            arr.push_back(i);
            utils(n, k, arr, i + 1);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> a;
        utils(n, k, a, 1);
        return ans;
    }
};