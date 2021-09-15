class Solution {
public:
    int findLHS(vector<int> &nums)
    {

        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        int ans = 0;
        for(auto p: freq){
            int next = p.first + 1;
            if(freq.find(next) != freq.end())
                ans = max(ans, p.second + freq[next]);
        }
        return ans;
    }
};