class Solution {
public:
    string tictactoe(vector<vector<int>> &moves)
{
    vector<int> row(3,0), col(3,0);
    int left = 0, right = 0, player = 1;
    for(auto move: moves){
        int r = move[0];
        int c = move[1];

        row[r] += player;
        col[c] += player;

        if(r == c)
            left += player;
        if(r+c == 2)
            right += player;

        if(abs(row[r]) == 3 || abs(col[c]) == 3 || abs(left) == 3 || abs(right) == 3){
            return player == 1 ? "A" : "B";
        }
        player *= -1;
    }
    return moves.size() == 9 ? "Draw" : "Pending";
}
};