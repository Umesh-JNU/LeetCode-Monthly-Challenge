class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, int> mp;
        for(auto x: words)
            mp[x]++;
        
        int n = s.length();
        int m;
        for(auto word: mp){
            m = word.first.length();
            if(m <= n){
                int i=0, j=0;
                while(i < m && j < n){
                    if(s[j]==word.first[i]){
                        i++; j++;
                    }
                    else{
                        j++;
                    }
                }
                if(i==m){
                    count += word.second;
                }
            }
        }
        return count;
    }
};