class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        for (int i = 0; i < strs[0].size(); i++)
        {
            string temp;
            for (int j = 0; j < strs.size(); j++)
            {
                temp += strs[j][i];
            }
            string s = temp;
            sort(temp.begin(), temp.end());
            // cout << "temp=" << temp << " s=" << s << endl;
            if (s != temp){
                count++;
            }
        }
        return count;
    }
};