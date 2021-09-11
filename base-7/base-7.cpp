class Solution {
public:
    string convertToBase7(int num)
    {
        if(num == 0)
            return "0";
        bool sign = num < 0;
        num = abs(num);
        string ans;
        while (num)
        {
            ans.insert(0, to_string(num % 7));
            num /= 7;
        }
        return sign ? ans.insert(0, 1, '-') : ans;
    }
};