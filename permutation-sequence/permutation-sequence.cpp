class Solution {
public:
//     Brute Force
//     vector<string> permutations;
//     void generateAllPossiblePermutations(string ss, int n, int idx)
//     {
//         if (idx >= n)
//         {
//             permutations.push_back(ss);
//             return;
//         }

//         for (int i = idx; i < n; i++)
//         {
//             swap(ss[i], ss[idx]);
//             generateAllPossiblePermutations(ss, n, idx + 1);
//             swap(ss[i], ss[idx]);
//         }
//     }
//     string getPermutation(int n, int k)
//     {
//         string s;
//         for (int i = 1; i <= n; i++)
//             s += to_string(i);

//         generateAllPossiblePermutations(s, n, 0);
//         // for (auto p : permutations)
//         // {
//         //     cout << p << " ";
//         // }
//         sort(permutations.begin(), permutations.end());
//         return permutations[k-1];
//     }
    string getPermutation(int n, int k){
        k--;
        int fact[n + 1];
        fact[0] = 1;
        string ans, s;
        for (int i = 1; i <= n; i++)
        {
            s += to_string(i);
            fact[i] = fact[i - 1] * i;
        }

        int ith_char = 0;
        for (int i = n; i >= 1; i--)
        {
            ith_char = k / fact[i - 1];
            k = k % fact[i - 1];
            // cout << k << " " << fact[i-1] << " " << ith_char << endl;
            ans += s[ith_char];
            s.erase(ith_char, 1);
        }
        return ans;
    }
};