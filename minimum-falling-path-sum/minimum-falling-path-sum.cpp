class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int left, down, right;
        for (int i = n - 2; i >= 0; i--){
            for (int j = 0; j < n; j++){
                left = (j == 0) ? INT_MAX : matrix[i + 1][j - 1];
                down = matrix[i + 1][j];
                right = (j == n - 1) ? INT_MAX : matrix[i + 1][j + 1];
                matrix[i][j] += min(min(left, down), right);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, matrix[0][i]);

        return ans;
    }
};