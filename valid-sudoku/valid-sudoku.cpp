class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;
        unordered_map<int, vector<int>> box;
        for(int i=0; i<9; i++){
            row[i] = vector<int>(10, 0);
            col[i] = vector<int>(10, 0);
            box[i] = vector<int>(10, 0);
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int b = 3*(i/3)+(j/3);
                    int val = board[i][j]-'0';
                    if(row[i][val] || col[j][val] || box[b][val]) return false;
                    
                    row[i][val] = 1;
                    col[j][val] = 1;
                    box[b][val] = 1;
                }
            }
        }
        
        return true;
    }
};