class Solution {
public:
    string reverseWords(string s)
    {
        int i = 0;
        // removing leading 0s
        while (i < s.size() && s[i] == ' ')
            i++;
        s.erase(0, i);
        // removing trailing 0s
        int j = s.size() - 1;
        while (j >= 0 && s[j] == ' ')
            j--;
        s.erase(j + 1);
        // removing extras 0s
        i = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1] && s[i] == ' ')
            {
                s.erase(s.begin() + i - 1);
                i--;
            }
        }

        reverse(s.begin(), s.end());

        int st = 0;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                for (int j = i - 1; j > st; j--)
                {
                    swap(s[j], s[st]);
                    st++;
                }
                st = i+1;
            }
        }

        // reversing last word
        for (i = s.size() - 1; i > st; i--)
        {
            swap(s[i], s[st]);
            st++;
        }
        return s;
    }
};