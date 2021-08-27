class Solution {
public:
    bool isValidSerialization(string preorder) {
        int v = 1, n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            if (preorder[i] == ',')
                continue;
            
            v--;
            if (v < 0)
                return false;

            if (preorder[i] != '#')
            {
                while (i < n && isdigit(preorder[i]))
                    i++;
                
                i--;
                v += 2;
            }
        }
        return v == 0;
    }
};