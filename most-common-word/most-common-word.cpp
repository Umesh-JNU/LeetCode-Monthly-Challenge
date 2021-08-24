class Solution {
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        set<string> ban(banned.begin(), banned.end());
        string t;
        map<string, int> freq;
        for (int i = 0; i < paragraph.size(); i++){
            char c = paragraph[i];
            if(c == ' ' || c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.'){
                if(t.size() > 0)
                    freq[t]++;
                t.clear();
            }
            else{
                t += tolower(c);
            }
        }
        // for the last word (if not mapped)
        if(t.size() > 0) freq[t]++;
        
        int ans = 0;
        string res;
        for(auto p: freq){
            if(ban.find(p.first) == ban.end()){
                if(ans < p.second){
                    ans = p.second;
                    res = p.first;
                }
            }
        }
        return res;
    }
};