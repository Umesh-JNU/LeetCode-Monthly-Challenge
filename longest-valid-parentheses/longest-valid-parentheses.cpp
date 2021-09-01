class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> stk;
        stk.push(-1);
        int maxlen = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                stk.push(i);
            else
            {
                stk.pop();
                if (stk.empty())
                    stk.push(i);
                else
                    maxlen = max(maxlen, i - stk.top());
            }
        }
        return maxlen;
    }
};