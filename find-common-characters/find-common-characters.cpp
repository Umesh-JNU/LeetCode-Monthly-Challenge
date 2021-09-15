class Solution {
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> alpha(26, INT_MAX);
        for(auto word: words){
            vector<int> temp(26, 0);
            for(auto c: word)
                temp[c - 'a']++;

            for (int i = 0; i < 26; i++)
                alpha[i] = min(alpha[i], temp[i]);
        }

        vector<string> ans;
        for (int i = 0; i < 26; i++){
            for (int j = 0; j < alpha[i]; j++)
                ans.push_back(string(1, i + 'a'));
        }
        return ans;
    }
};