class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n = mat.size();
        int i=0, j=n-1;
        while(i <= j){
            if(i != j) sum += mat[i][i]+mat[i][j]+mat[j][i]+mat[j][j];
            else sum += mat[i][i];
            i++;
            j--;
        }
        return sum;
    }
};