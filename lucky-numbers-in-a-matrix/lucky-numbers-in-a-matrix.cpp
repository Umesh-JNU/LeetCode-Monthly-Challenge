class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<int> min_row(m, 0);
        for(int i=0; i<m; i++)
            min_row[i] = *min_element(matrix[i].begin(), matrix[i].end());

        for (int j = 0; j < n; j++){
            int max_col = 0;
            for (int i = 0; i < m; i++){
                if(matrix[max_col][j] < matrix[i][j])
                    max_col = i;
            }
            if(matrix[max_col][j] == min_row[max_col])
                ans.push_back(min_row[max_col]);
        }

        return ans;
    }
};