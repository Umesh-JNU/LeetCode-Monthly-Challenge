class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<bool> ans(n, false);
        for (int i = 0; i < n; i++){
            vector<int> vec(nums.begin() + l[i], nums.begin() + r[i]+1);
            sort(vec.begin(), vec.end());

            if(vec.size() == 2)
                ans[i] = true;
            else{
                int j;
                for (j = 2; j < vec.size(); j++){
                    if(vec[j]-vec[j-1] != vec[j-1]-vec[j-2])
                        break;
                }
                if(j == vec.size())
                    ans[i] = true;
            }
        }
        return ans;
    }
};