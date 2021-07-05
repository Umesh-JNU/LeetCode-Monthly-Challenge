class Solution {
public:
    void dfs(vector<vector<int>> &img, int i, int j, int src, int newColor)
    {
        if(img[i][j]!=src){
            return;
        }
        img[i][j] = newColor;

        // top
        if(i-1 >= 0)
            dfs(img, i - 1, j, src, newColor);
        // bottom
        if(i+1 < img.size())
            dfs(img, i + 1, j, src, newColor);
        // left
        if(j-1 >= 0)
            dfs(img, i, j - 1, src, newColor);
        // right
        if(j+1 < img[0].size())
            dfs(img, i, j + 1, src, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int source = image[sr][sc];
        if(source==newColor)
            return image;

        dfs(image, sr, sc, source, newColor);
        return image;
    }
};