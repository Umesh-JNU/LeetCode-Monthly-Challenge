class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(auto c: columnTitle){
            ans = ans * 26 + (c - 64);
        }
        return ans;
    }
};