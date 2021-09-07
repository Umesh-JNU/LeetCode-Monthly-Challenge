class Solution {
public:
vector<string> summaryRanges(vector<int> &nums)
    {
        int n = nums.size();
        vector<string> ans;
        string ss;
        int i = 0, j;
        while (i<n)
        {
            ss.clear();
            ss+=to_string(nums[i]);
            j = i + 1;
            while (j<n && nums[j]==nums[j-1]+1)
                j++;

            if(j != i+1){
                ss += "->";
                ss += to_string(nums[j - 1]);
            }
            ans.push_back(ss);
            i = j;
            // cout << ss << "  " << i << "  " << j << endl;
        }
        return ans;
    }
};