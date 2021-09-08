class Solution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int n = s.size(), i = 0, j = 0, gap = 2*(numRows - 1);
        // cout << gap << endl;
        string ss;
        while (i != numRows)
        {
            j = i;
            while (j < n)
            {
                // cout << "j="<< j << " ";
                ss += s[j];

                j += gap;
                if (i != 0 && i != numRows-1 && j-(2*i) < n){
                    // cout << (j-(2*i)) << " ";
                    ss += s[j - (2 * i)];
                }
            }
            // cout << endl;
            i++;
        }
        return ss;
    }
};