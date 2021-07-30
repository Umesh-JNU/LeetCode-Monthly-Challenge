class Solution {
public:
    vector<pair<int, int>> points = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // cout << mat[i][j] << " ";
                if(mat[i][j] == 0)
                    q.push(make_pair(i, j));
                else
                    mat[i][j] = -1;
            }
        }

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            // cout << "\n" << p.first << " " << p.second;
            for(int i=0; i<4; i++){
                int xd = p.first + points[i].first;
                int yd = p.second + points[i].second;

                if(xd < 0 || xd >= m || yd < 0 || yd >= n || mat[xd][yd] != -1)
                    continue;

                // cout << "\n" << xd << " " << yd << " " << mat[xd][yd];
                mat[xd][yd] = mat[p.first][p.second] + 1;
                q.push(make_pair(xd, yd));
            }
        }
        return mat;
    }
};