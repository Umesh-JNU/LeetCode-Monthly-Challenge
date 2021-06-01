class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        int n = products.size();
        vector<vector<string>> res(searchWord.length(), vector<string> {});
        string prefix;
        int start = 0, idx;
        for (int i = 0; i < searchWord.length(); i++)
        {
            prefix += searchWord[i];
            // get the first matching index
            idx = lower_bound(products.begin() + start, products.end(), prefix) - products.begin();

            for (int j = idx; j < min(idx + 3, n) && !products[j].compare(0, prefix.length(), prefix); j++){
                res[i].push_back(products[j]);
            }
            start = idx;
        }
        return res;
    }
};