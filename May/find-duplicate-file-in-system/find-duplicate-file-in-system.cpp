class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        // to map the content to its path
        map<string, vector<string>> mp;
        
        /**
         * for each string first split and store them in the vector
         * STEP 1 :-
         * "root/a 1.txt(abcd) 2.txt(efsfgh)"
         * 0 -> "root/a"
         * 1 -> "1.txt(abcd)"
         * 2 -> "2.txt(efsfgh)"
         * 
         * STEP 2 :-
         * now get the content eg. abcd and map it to
         * ie. abcd -> ["root/a/1.txt"]
         *   efsfgh -> ["root/a/2.txt"]
         *
         * STEP 3 :-
         * now check whether there is duplicate files with the same content
         * eg. length of 
         *     abcd -> ["root/a/1.txt"] = 1
         *   efsfgh -> ["root/a/2.txt"] = 1
         * it means no duplicate file
         */
        
        for(auto path : paths){
            // STEP 1
            stringstream ss(path);
            string word;
            vector<string> split; // vector to store
            while (ss >> word) {
                // cout << word << endl;
                split.push_back(word); 
            }
            
            // STEP 2
            for(int i=1; i<split.size(); i++){
                int idx = split[i].find('(');
                // cout << "idx = " << idx << endl;
                string content = split[i].substr(idx+1, (len - idx - 1)); // content
                
                int len = split[i].size();
                // cout << "content = " << content << endl;
                string file = split[0] + "/" + split[i].substr(0, idx); // file
                // cout << "file = " << file << endl;
                mp[content].push_back(file);
            }
        }

        vector<vector<string>> res;
        for(auto duplicate : mp){
            // STEP 3
            if(duplicate.second.size()>1)
                res.push_back(duplicate.second);
        }

        return res;
    }
};
