class Solution {
public:
//     int calculateMinimumHP(vector<vector<int>> &dungeon)
//     {
//         int n = dungeon.size();
//         int m = dungeon[0].size();
//         for (int i = 1; i < m; i++)
//             dungeon[0][i] += dungeon[0][i - 1];

//         for (int i = 1; i < n; i++)
//             dungeon[i][0] += dungeon[i - 1][0];

//         for (int i = 1; i < n; i++){
//             for (int j = 1; j < m; j++){
//                 if(abs(dungeon[i-1][j] < abs(dungeon[i][j-1])))
//                     dungeon[i][j] += dungeon[i - 1][j];
//                 else
//                     dungeon[i][j] += dungeon[i][j - 1];
//             }
//         }
//         return dungeon[n - 1][m - 1] <= 0 ? 1-dungeon[n - 1][m - 1] : 1;
//     }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size(), n = dungeon.front().size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX)); // Maximum penalty so you don't go out of bounds!
	
	// The requirement to "move to a different room" at the end: you must be alive!
    dp[m][n - 1] = 1; dp[m - 1][n] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
			// Give me the less costly room and add the cost of the current room,
			// or 1 if the cost for this room (which is actually a benefit) covers the next room!
            dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
        }
    }

    return dp.front().front();
    }
};