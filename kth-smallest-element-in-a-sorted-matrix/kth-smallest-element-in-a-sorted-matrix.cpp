class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        if(n==1 || k==1)
            return matrix[0][0];
        
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(low < high){
            int mid = low + (high-low)/2;
            int cnt = count(matrix, n, mid);
            
            if(cnt >= k)
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
    
    int count(vector<vector<int>> matrix, int n, int target){
        int row = n-1;
        int col = 0;
        int cnt = 0;
        
        while(row >=0 && col <n){
            if(matrix[row][col] > target)
                row--;
            else{
                cnt += row + 1;
                col++;
            }
        }
        
        return cnt;
    }
};