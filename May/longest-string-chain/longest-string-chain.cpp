class Solution {
public:
    static bool compare(string s1, string s2){
        return s1.length() < s2.length();
    }
    int longestStrChain(vector<string>& words) {
        // word.length == 0
        int n = words.size();
        if(n==0){
            return 0;
        }
        
        sort(words.begin(), words.end(), compare);
        int res = 0;
        map<string, int> mp;
        string deletechar;
        for(int i=0; i<n; i++){
            mp[words[i]] = 1;
            // now keep deleting each char and check whether it exists in the mp or not
            // if not do nothing and else mp[words[i]] = max(mp[words[i]], deletechar);
            // cout << i << endl;
            for(int j=1; j<=words[i].length(); j++){
                // cout << j << endl;
                // cout << "- " << words[i].substr(0,j-1) << endl;
                // cout << "--" << words[i].substr(j) << endl;
                deletechar = words[i].substr(0,j-1) + words[i].substr(j);
                
               if(mp[deletechar]){
                    mp[words[i]]=max(mp[words[i]], mp[deletechar]+1);
                }
            }
            res = max(res, mp[words[i]]);
        }
        return res;
    }
};