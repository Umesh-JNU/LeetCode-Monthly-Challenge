class Solution {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        int n = pattern.length(), flag;
        vector<string> res;
        for(auto word: words){
            map<char, char> pointTo;
            map<char, char> pointBy;
            flag = 1;
            for(int i=0; i<word.length(); i++){
                if(word.length() == n){
                    // check whether word's char is pointed or not
                    // if not pointed and current pattern's char is not pointing to any other word's char
                    // then char will point to each other
                    if(!pointTo[pattern[i]] && !pointBy[word[i]]){
                        pointBy[word[i]]=pattern[i];
                        pointTo[pattern[i]]=word[i];
                    }
                    else if((pointBy[word[i]] && !pointTo[pattern[i]]) || 
                            (!pointBy[word[i]] && pointTo[pattern[i]]) ||
                            (pointBy[word[i]] && pointTo[pattern[i]] && (pointBy[word[i]]!=pattern[i] || pointTo[pattern[i]] != word[i]))){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag){
                res.push_back(word);
            }
        }
        return res;
    }
};