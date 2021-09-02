class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> mails;
        for(auto email : emails){
            // break
            int idx = email.find('@');
            string before = email.substr(0, idx);
            string after = email.substr(idx + 1);

            int plus = before.find('+');
            string without_dots;
            for (int i = 0; i < (plus == -1 ? before.size() : plus); i++)
            {
                if(before[i] != '.')
                    without_dots += before[i];
            }

            mails[without_dots + '@' + after]++;
        }
        return mails.size();
    }
};