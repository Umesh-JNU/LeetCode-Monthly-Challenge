// brute for approach
// time complexity = O(N^2 * l^2)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int res = 0;
        int flag;
        for (int i = 0; i < n-1; i++){
            for (int j = i + 1; j < n; j++){
                flag = 1;
                for(auto c: words[i]){
                    if(words[j].find(c)!=string::npos){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    int x = words[i].length()*words[j].length();
                    res = max(res, x);
                }
            }
        }
        return res;
    }
};

// efficient approach using bit-manipulation
// time-complexity O(N^2)
// But it can further be optimized
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bitCodeVal;
        int p;
        for (auto word : words)
        {
            p = 0;
            for (auto c : word)
            {
                p |= 1 << (c - 'a');
            }
            bitCodeVal.push_back(p);
        }

        int res = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (!(bitCodeVal[i] & bitCodeVal[j]))
                {
                    int x = words[i].length() * words[j].length();
                    res = max(res, x);
                }
            }
        }
        
        return res;
    }
};
