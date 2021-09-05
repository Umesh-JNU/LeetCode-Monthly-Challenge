class Solution {
public:
    string multiply(string num1, string num2) {
        string ans;
        int carry, prod;
        for (int i = num1.size() - 1; i >= 0; i--)
        {
            carry = 0;
            string s;
            s.insert(0, num1.size() - i - 1, '0');
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                prod = (num1[i] - '0') * (num2[j] - '0')+carry;
                char c = (prod % 10) + '0';
                carry = prod / 10;
                s.insert(0, 1, c);
            }
            if(carry)
                s.insert(0, 1, carry+'0');

            ans.insert(0, s.size() - ans.size(), '0');
            // cout << ans << endl;
            carry = 0;
            for (int k = s.size() - 1; k >= 0; k--){
                int sum = (ans[k] - '0') + (s[k] - '0') + carry;
                ans[k] = (sum % 10)+'0';
                carry = sum / 10;
            }
            if(carry)
                ans.insert(0, 1, carry + '0');
            // cout << ans << " " << s << endl;
        }
        return ans[0]=='0' ? "0" : ans;
    }
};