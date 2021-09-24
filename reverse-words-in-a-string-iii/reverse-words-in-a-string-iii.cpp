class Solution {
public:
    void revUtils(string &s, int i, int j){
        while(i <= j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s)
    {
        vector<int> ss;
        ss.push_back(-1);
        for (int i = 0; i < s.size(); i++){
            if(s[i]==' ')
                ss.push_back(i);
        }

        int j;
        for (j = 1; j < ss.size(); j++)
            revUtils(s, ss[j - 1] + 1, ss[j] - 1);
        revUtils(s, ss[j - 1] + 1, s.size() - 1);
        return s;
    }
};