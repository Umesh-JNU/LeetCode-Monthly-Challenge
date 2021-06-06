class Solution {
public:
    #define ll long long
    
    bool isPalindrome(string s)
    {
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
    bool satisfyingCond(ll left, ll right, string s){
        ll num = stoll(s);
        if (num > 1e9) return false;
        num *= num;
        return num >= left && num <= right && isPalindrome(to_string(num));
    }
    int superpalindromesInRange(string left, string right){
        ll l = stoll(left);
        ll r = stoll(right);

        int ans = 0;
        // check from num 1-9 ie. single digit
        for(int i=1; i<10; i++){
            ans += satisfyingCond(l, r, to_string(i)) ? 1 : 0;
        }

        // check for all possible palindromes [1, 1e4]
        for(ll i=1; i<1e4; i++){
            string s1 = to_string(i);
            string s2 = s1;
            reverse(s2.begin(), s2.end());

            ans += satisfyingCond(l, r, s1+s2) ? 1 : 0;

            for(int j=0; j<10; j++){
                string temp = s1;
                temp += (j + '0');

                ans += satisfyingCond(l, r, temp + s2) ? 1 : 0;
            }
        }
        return ans;
    }
};