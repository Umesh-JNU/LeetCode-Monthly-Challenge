class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        if (n == 1)
            return s;

        string ans;
        for(auto c: s){
            (ans.empty() || ans.back() != c) ? ans.push_back(c) : ans.pop_back();
        }

        return ans;
    }
};