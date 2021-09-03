class Solution {
public:
    void addTrailingZero(string &a, int n){
        for (int i = 0; i < n; i++)
            a.insert(0, 1, '0');
    }
    string addBinary(string a, string b)
    {
        int n1 = a.size(), n2 = b.size(), n = max(n1, n2);
        if(n1 < n2){
            addTrailingZero(a, n2 - n1);
        }else{
            addTrailingZero(b, n1 - n2);
        }
        // cout << a << " " << b << endl;

        string ans(n, '0');
        char carry = '0';
        for (int i = n-1; i >= 0; i--){
            // cout << i << " " << a[i] << " -- " << b[i] << endl;
            if(a[i]=='1' && b[i]=='1'){
                if(carry == '1')
                    ans[i] = '1';
                carry = '1';
            }
            else if(a[i]=='0' && b[i]=='0'){
                if(carry == '1'){
                    ans[i] = '1';
                    carry = '0';
                }
            }
            else{
                if(carry == '0')
                    ans[i] = '1';
                else
                    carry = '1';
            }
        }
        if(carry == '1')
            ans.insert(0, 1, '1');

        return ans;
    }
};