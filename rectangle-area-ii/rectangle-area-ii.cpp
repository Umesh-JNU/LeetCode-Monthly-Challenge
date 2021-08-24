class Solution {
public:
    #define ll long long
    #define MOD 1000000007

    int rectangleArea(vector<vector<int>> &rectangles)
    {
        set<int> xcord, ycord;
        for (auto r : rectangles)
        {
            xcord.insert(r[0]);
            xcord.insert(r[2]);
            ycord.insert(r[1]);
            ycord.insert(r[3]);
        }
        vector<int> xcord_vec(xcord.begin(), xcord.end()); // unique sorted x-co-ordinate
        vector<int> ycord_vec(ycord.begin(), ycord.end()); // unique sorted y-co-ordinate
        unordered_map<int, int> x, y;
        int idx = 0;
        for (auto xc : xcord)
            x[xc] = idx++;

        idx = 0;
        for (auto yc : ycord)
            y[yc] = idx++;

        vector<vector<int>> grid(x.size(), vector<int>(y.size(), 0));
        for (auto r : rectangles)
        {
            for (int i = x[r[0]]; i < x[r[2]]; i++)
            {
                for (int j = y[r[1]]; j < y[r[3]]; j++)
                {
                    grid[i][j] = 1;
                }
            }
        }

        ll ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += (ll)(xcord_vec[i+1] - xcord_vec[i]) * (ycord_vec[j+1] - ycord_vec[j]);
                }
            }
        }

        return ans%MOD;
    }
};