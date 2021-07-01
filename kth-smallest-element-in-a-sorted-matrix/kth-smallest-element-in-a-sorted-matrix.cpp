class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        if(n==1 || k==1)
            return matrix[0][0];

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < n;i++)
            pq.push({matrix[i][0], i, 0});

        int j = 0;
        vector<int> cur;
        while(j<k){
            cur = pq.top();
            pq.pop();

            // cout << "matrix["<<cur[1]<<"]["<<cur[2]<<"] = "<<matrix[cur[1]][cur[2]] << endl;
            if(cur[2] + 1 < n){
                pq.push({matrix[cur[1]][cur[2]+1], cur[1], cur[2] + 1});
            }
            j++;
        }

        return cur[0];
    }
};