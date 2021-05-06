class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res= {{1}};
        for(int i=1; i<numRows; i++){
            vector<int> ithRow(i+1);
            for(int j=0; j<=i; j++){
                if(j==0 || j==i) ithRow[j]=1;
                else{
                    ithRow[j] = res[i-1][j-1]+res[i-1][j];
                }
            }
            res.push_back(ithRow);
        }
        return res;
    }
};