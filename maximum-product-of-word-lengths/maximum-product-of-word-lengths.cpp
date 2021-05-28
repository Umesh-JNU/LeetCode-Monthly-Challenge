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