class Solution {
public:
    bool isInteger(string s){
        // empty string
        if(s.empty()) return false;
        if(s[0]=='+' || s[0]=='-'){
            s = s.substr(1);
        }
        for(int i=0; i<s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9') continue;
            return false;
        }
        // if '+' is passed then string will be empty so we have to check whether it is empty
        // it must have atleast one integer
        return !s.empty();
    }
    
    bool isDecimal(string s){
        // empty string
        if(s.empty()) return false;
        if(s[0]=='+' || s[0]=='-'){
            s = s.substr(1);
        }
        // count the number of dots
        int cnt = count(s.begin(), s.end(), '.');
        if(cnt==1){
            // else
            // find the position of .
            int pos = find(s.begin(), s.end(), '.') - s.begin();
            // now check before and after the pos 
            // whether it has only integer
            // before
            for(int i=0; i<pos; i++){
                if(s[i] >= '0' && s[i] <= '9') continue;
                return false;
            }
            // after
            for(int i=pos+1; i<s.size(); i++){
                if(s[i] >= '0' && s[i] <= '9') continue;
                return false;
            }
            
            // check if the string has only single .
            // then above statement will not run
            // in that we have to check it length is > 1
            return s.size() > 1;
        }
        // else for count==0 or count > 1
        return false;
    }
    
    bool isNumber(string s) {
        int n = s.size();
        int cnt = 0;
        // count the e/E
        for(int i=0; i<n; i++){
            cnt += (s[i]=='e' || s[i]=='E');
        }
        // if greater than 1
        if(cnt > 1) return false;
        if(cnt==1){
            // find the position of e/E
            int pos=0;
            for(int i=0; i<s.size(); i++){
                if(s[i]=='e' or s[i]=='E'){
                    pos = i;
                    break;
                }
            }
            
            // check for the after part of this pos whether its valid integer or not
            if(!isInteger(s.substr(pos+1)))
                return false;
            
            // for checking the before part
            s = s.substr(0, pos);
        }
        
        // check the before part whether it is either integer or decimal
        // or also check for the condition when e/E is not present
        return isDecimal(s) || isInteger(s);
    }
};