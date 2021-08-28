class Solution {
public:
    bool isAlnum(char c){
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (!isAlnum(s[l])){
                l++;
                continue;
            }
            if(!isAlnum(s[r])){
                r--;
                continue;
            }

            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }

        return true;
    }
};