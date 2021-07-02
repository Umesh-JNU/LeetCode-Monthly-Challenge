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

int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    if (n == 1 || k == 1)
        return matrix[0][0];

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++)
        pq.push({matrix[i][0], i, 0});

    int j = 0;
    vector<int> cur;
    while (j < k)
    {
        cur = pq.top();
        pq.pop();

        cout << "matrix[" << cur[1] << "][" << cur[2] << "] = " << matrix[cur[1]][cur[2]] << endl;
        if (cur[2] + 1 < n)
        {
            pq.push({matrix[cur[1]][cur[2] + 1], cur[1], cur[2] + 1});
        }
        j++;
    }

    return cur[0];
}
