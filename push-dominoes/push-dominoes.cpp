class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.length();
        vector<int> left(n);
        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == '.')
                left[i] = i + 1 == n ? -1 : left[i + 1];
            else if (dominoes[i] == 'L')
                left[i] = i;
            else
                left[i] = -1;
        }

        vector<int> right(n);
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == '.')
                right[i] = i - 1 == -1 ? -1 : right[i - 1];
            else if (dominoes[i] == 'R')
                right[i] = i;
            else
                right[i] = -1;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == '.')
            {
                if (left[i] == -1 && right[i] != -1)
                {
                    dominoes[i] = dominoes[right[i]];
                }
                else if (left[i] != -1 && right[i] == -1)
                {
                    dominoes[i] = dominoes[left[i]];
                }
                else if (left[i] != -1 && right[i] != -1)
                {
                    int a = abs(left[i] - i);
                    int b = abs(right[i] - i);
                    if (a < b)
                    {
                        dominoes[i] = dominoes[left[i]];
                    }
                    else if (a > b)
                    {
                        dominoes[i] = dominoes[right[i]];
                    }
                }
            }
        }

        return dominoes;
    }
};