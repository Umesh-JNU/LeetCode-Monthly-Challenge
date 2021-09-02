class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto n: nums) freq[n]++;
        
        int ans = 0;
        for(auto p: freq){
            if(p.second == 1)
                ans += p.first;
        }
        
        return ans;
    }
};