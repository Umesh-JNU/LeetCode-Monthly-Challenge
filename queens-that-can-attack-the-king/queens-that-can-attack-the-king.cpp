class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<char>> board(8, vector<char>(8, ' '));
        for(auto cord: queens){
            board[cord[0]][cord[1]] = 'Q';
        }

        vector<vector<int>> ans;
        int y = king[0], x = king[1];

        // above
        for (int i = y - 1; i >= 0; i--){
            if(board[i][x] == 'Q'){
                ans.push_back({i, x});
                break;
            }
        }
        // bottom
        for (int i = y + 1; i < 8; i++){
            if(board[i][x] == 'Q'){
                ans.push_back({i, x});
                break;
            }
        }
        // left
        for (int i = x - 1; i >= 0; i--){
            if(board[y][i] == 'Q'){
                ans.push_back({y, i});
                break;
            }
        }
        // right
        for (int i = x + 1; i < 8; i++){
            if(board[y][i] == 'Q'){
                ans.push_back({y, i});
                break;
            }
        }
        // top-left
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
            if(board[j][i] == 'Q'){
                ans.push_back({j, i});
                break;
            }
        }
        // top-right
        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++){
            if(board[j][i] == 'Q'){
                ans.push_back({j, i});
                break;
            }
        }
        // bottom-left
        for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--){
            if(board[j][i] == 'Q'){
                ans.push_back({j, i});
                break;
            }
        }
        // bottom-right
        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++){
            if(board[j][i] == 'Q'){
                ans.push_back({j, i});
                break;
            }
        }
        return ans;
    }
};