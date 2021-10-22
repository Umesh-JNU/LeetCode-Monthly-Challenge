class Solution {
public:
    static bool comp(pair<int, char> a, pair<int, char> b) {
        return a.first > b.first;
    }
    string frequencySort(string s)
    {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        vector<pair<int, char>> v;
        for (auto p : freq)
            v.push_back(make_pair(p.second, p.first));
        sort(v.begin(), v.end(), comp);
        int k = 0;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].first; j++)
            {
                s[k++] = v[i].second;
            }
        }
        return s;
    }
};