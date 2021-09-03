class Solution {
public:
    static bool comp(string a, string b){
        return a.length() < b.length();
    }
    string longestCommonPrefix(vector<string> &strs)
    {
        string ss = *min_element(strs.begin(), strs.end(), comp);
        for (int c = 0; c < ss.size(); c++)
        {
            for (int i = 0; i < strs.size(); i++){
                if(strs[i][c] != ss[c])
                    return ss.substr(0, c);
            }
        }
        return ss;
    }
};