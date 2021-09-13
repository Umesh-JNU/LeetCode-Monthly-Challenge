class Solution {
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string ss;
        for (auto e : words)
        {
            ss += e;
            if (ss == s)
                return true;
        }
        return false;
    }
};