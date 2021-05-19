class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> mp;
        for(auto path : paths){
            stringstream ss(path);
            string word;
            vector<string> split;
            while (ss >> word) {
                // cout << word << endl;
                split.push_back(word);
            }

            for(int i=1; i<split.size(); i++){
                int idx = split[i].find('(');
                // cout << "idx = " << idx << endl;

                int len = split[i].size();
                string content = split[i].substr(idx+1, (len - idx - 1));
                // cout << "content = " << content << endl;
                string file = split[0] + "/" + split[i].substr(0, idx);
                // cout << "file = " << file << endl;
                mp[content].push_back(file);
            }
        }

        vector<vector<string>> res;
        for(auto duplicate : mp){
            if(duplicate.second.size()>1)
                res.push_back(duplicate.second);
        }

        return res;
    }
};