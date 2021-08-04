class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> curInt = intervals[0];
        for (auto interval : intervals)
        {
            if (curInt[1] >= interval[0])
            {
                curInt[1] = max(curInt[1], interval[1]);
            }
            else
            {
                ans.push_back(curInt);
                curInt = interval;
            }
        }
        ans.push_back(curInt);
        return ans;
    }
};