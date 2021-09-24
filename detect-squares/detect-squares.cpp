class DetectSquares {
public:
    DetectSquares() {
        plane = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        plane[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        long long ans=0;
        int x = point[0];
        int y = point[1];
        for(int d=1; d<1001; d++){
            int x1 = x+d;
            int x2 = x-d;
            int y1 = y+d;
            int y2 = y-d;
            /* ___
              |   |
            x,y___| */
            if(y1 <= 1000 && x1 <= 1000)
                ans += (plane[y1][x] * plane[y1][x1] * plane[y][x1]);// * (plane[y][x] ? plane[y][x] : 1));
            /* ___
              |   |
              |___x,y */
            if(y1 <= 1000 && x2 >=0)
                ans += (plane[y1][x] * plane[y1][x2] * plane[y][x2]);// * (plane[y][x] ? plane[y][x] : 1));
            /*  x,y___
                  |   |
                  |___| */
            if(y2 >= 0 && x1 <= 1000)
                ans += (plane[y2][x] * plane[y2][x1] * plane[y][x1]);// * (plane[y][x] ? plane[y][x] : 1));
            /* ___x,y
              |   |
              |___| */
            if(y2 >= 0 && x2 >= 0)
                ans += (plane[y2][x] * plane[y2][x2] * plane[y][x2]);// * (plane[y][x] ? plane[y][x] : 1));
        }
        return ans;
    }
private:
    vector<vector<int>> plane;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */