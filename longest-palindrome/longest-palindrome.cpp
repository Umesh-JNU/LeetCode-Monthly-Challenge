class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(auto c: s)freq[c]++;
        
        int ans = 0;
        int odd = 0;
        for(auto p: freq){
            if(p.second % 2 == 0) ans += p.second;
            else{
                odd = 1;
                ans += (p.second / 2)*2;
            }
        }
        
        if(odd) ans++;
        return ans;
    }
};