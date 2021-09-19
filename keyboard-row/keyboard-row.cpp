class Solution {
public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> ans;
        vector<set<char>> rows = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
                                  {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
                                  {'z', 'x', 'c', 'v', 'b', 'n', 'm'}};

        int i, j;
        for(auto word: words){
            i = 0;
            while(rows[i].count(tolower(word[0])) == 0)
                i++;

            for (j = 1; j < word.size(); j++){
                if(rows[i].count(tolower(word[j])) == 0)
                    break;
            }
            if(j==word.size())
                ans.push_back(word);
        }
        return ans;
    }
};