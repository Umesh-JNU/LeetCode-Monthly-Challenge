class Solution {
public:
    bool isValid(vector<string> ans, int row, int col){
        int n = ans.size();
        //col
        for (int i = 0; i < n; i++){
            if(ans[i][col]=='Q')
                return false;
        }
        //row
        for (int i = 0; i < n; i++){
            if(ans[row][i]=='Q')
                return false;
        }
        //forward diagonal
        for (int i = row-1, j=col-1; i >= 0 && j >= 0; i--, j--){
            if(ans[i][j]=='Q')
                return false;
        }
        //backward diagonal
        for (int i = row-1, j=col+1; i >= 0 && j < n; i--, j++){
            if(ans[i][j]=='Q')
                return false;
        }
        return true;
    }
    void helper(vector<vector<string>> &res, vector<string> ans, int n, int ithRow)     {
        if(ithRow==n){
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++){
            if(isValid(ans, ithRow, i)){
                ans[ithRow][i] = 'Q';
                helper(res, ans, n, ithRow + 1);
                ans[ithRow][i] = '.';
            }
        }
    }
    int totalNQueens(int n)
    {
        string start = "";
        for (int i = 0; i < n; i++){
            start += ".";
        }

        vector<vector<string>> res;
        vector<string> ans(n, start);
        helper(res, ans, n, 0);
        return res.size();
    }
};