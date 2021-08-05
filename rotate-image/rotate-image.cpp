class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size();
        for (int i = 0; i < n-1; i++){
            for (int j = i + 1; j < n; j++){
                swap(m[i][j], m[j][i]);
            }
        }

        // reversing
        for (int r = 0; r < n; r++)
        {
            for (int i = 0; i < n / 2; i++){
                swap(m[r][i], m[r][n - i - 1]);
            }
        }
    }
};