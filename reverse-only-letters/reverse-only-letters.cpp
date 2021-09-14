class Solution {
public:
    bool isAlpha(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    string reverseOnlyLetters(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i <= j)
        {
            if(isAlpha(s[i]) && isAlpha(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else{
                if(!isAlpha(s[i]))
                    i++;
                if(!isAlpha(s[j]))
                    j--;
            }
        }
        return s;
    }
};