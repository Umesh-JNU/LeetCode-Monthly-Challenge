class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderRank(26, 0);
        for (int i = 0; i < 26; i++)
            orderRank[order[i] - 'a'] = i;

        for (int i = 0; i < words.size() - 1; i++)
        {
            int j = 0, l1 = words[i].length(), l2 = words[i+1].length();
            while (j < l1 && j < l2)
            {
                // cout << words[i][j] << " " << words[i + 1][j] << " " << orderRank[words[i][j] - 'a'] << " " << orderRank[words[i + 1][j] - 'a'] << endl;
                if (words[i][j] == words[i + 1][j])
                {
                    j++;
                    continue;
                }
                else if (orderRank[words[i][j] - 'a'] < orderRank[words[i + 1][j] - 'a'])
                    break;
                else
                    return false;
            }
            if((j == l1 || j == l2) && l1 > l2)
                return false;
        }
        return true;
    }
};