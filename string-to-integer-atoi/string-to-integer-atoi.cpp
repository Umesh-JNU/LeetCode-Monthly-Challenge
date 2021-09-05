class Solution {
public:
    int myAtoi(string s) {
        // ignoring leading whitespaces
        int i = 0;
        while (s[i] == ' ')
            i++;

        // Check for +/-
        bool neg = false;
        if(i < s.size() && (s[i] == '+' || s[i] == '-')){
            if(s[i]=='-')
                neg = true;
            i++;
        }

        // Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
        long long ans = 0;
        while (s[i] >= '0' && s[i] <= '9'){
            // cout << s[i] << " " << ans << " ";
            ans = (ans * 10) + (s[i++] - '0');
            if(ans >= INT_MAX) 
                break;
        }

        if(neg)
            ans *= -1;

        if(ans < INT_MIN)
            return INT_MIN;
        if(ans > INT_MAX)
            return INT_MAX;
        return ans;
        // return 0;
    }
};

/*
"42"               -> 42
"4.2"              -> 4
"   -4-5.0 "       -> -4
"   4-5. ab 0 "    -> 4
*/