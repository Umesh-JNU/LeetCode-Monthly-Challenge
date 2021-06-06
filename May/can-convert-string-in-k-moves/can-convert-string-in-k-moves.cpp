class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length()) return false;
        map<int, int> mp;
        int i, x;
        for(int j=0; j<s.length(); j++){
            i = t[j]-s[j];
            
            if(s[j] != t[j]){
                if(i < 0){
                    i+=26;
                }
                
                if(i > k){
                    return false;
                }
                
                if(!mp[i]){
                    mp[i]=1;
                }
                else{
                    if(mp[i]*26 + i > k){
                        return false;
                    }
                    
                    // increase the frequeny
                    mp[i]++;
                }
            }
        }
        return true;
    }
};