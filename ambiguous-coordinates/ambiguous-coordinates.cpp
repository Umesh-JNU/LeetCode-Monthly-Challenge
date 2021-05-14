class Solution {
public:
    vector<string> result;
    vector<string> putDots(string s){
        // cout << "s = " << s << endl;
        vector<string> dot = {s};
        for(int i=1; i<s.length(); i++){
            dot.push_back(s.substr(0,i)+'.'+s.substr(i));
        }
        for(int i=0; i<s.length(); i++){
            // cout << "-- "<<dot[i] << " " << endl;
        }
        return dot;
    }
    bool isValid(string s){
        int pos = find(s.begin(), s.end(), '.') - s.begin();
        // does not contain .
        if( pos == s.length()){
            if(s == "0") return true;
            else return !(s[0]=='0');
        }// contains .
        else{
            string part1 = s.substr(0, pos), part2 = s.substr(pos+1);
            // first part is not and starting with 0 eg. 012
            if(part1 != "0" && part1[0]=='0') return false;
            // else part1 = 0, then check for the second part which need not to end with 0 eg .120
            else return part2[part2.length()-1] != '0';
        }
    }
    void helper(string x, string y){
        vector<string> dotX = putDots(x);
        vector<string> dotY = putDots(y);

        for(auto x : dotX){
            if(isValid(x)){
                for(auto y : dotY){
                    if(isValid(y)){
                        result.push_back("(" +x+ ", " +y+ ")");
                    }
                }
            }
        }
    }
    vector<string> ambiguousCoordinates(string s)
    {
        s = s.substr(1, s.length()-2);
        cout << s << endl;
        for(int i=1; i<s.length(); i++){
            // cout << s.substr(0,i) << " " <<s.substr(i) << endl;
            helper(s.substr(0,i), s.substr(i));
        }

        return result;
    }
};