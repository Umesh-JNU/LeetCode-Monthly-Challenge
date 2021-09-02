class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(auto n: arr) freq[n]++;
        
        unordered_map<int, int> mp;
        for(auto p: freq){
            if(mp.find(p.second) != mp.end())
                return false;
            mp[p.second]++;
        }
        
        return true;
    }
};