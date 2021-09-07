class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int n1 = haystack.size(), n2 = needle.size();
        if (n2 == 0)
            return 0;
        if (n2 > n1)
            return -1;

        vector<int> start;
        for (int i = 0; i < n1; i++)
        {
            if (haystack[i] == needle[0])
                start.push_back(i);
        }

        int i, j;
        for(auto s: start){
            // cout << s << " ";
            i = s, j = 0;
            while (i < n1 && j < n2 && haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if(i == n1 && j != n2)
                return -1;
            else if((i != n1 || i == n1) && j == n2)
                return s;
        }
        return -1;
    }
};