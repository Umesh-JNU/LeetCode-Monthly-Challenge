class Solution {
public:
    int compare(int a, int b){
        if(a==b)
            return 0;
        return a > b ? 1 : -1;
    }
    int maxTurbulenceSize(vector<int> &arr)
    {
        int n = arr.size();
        if(n==1)
            return 1;
        int ans = 1;
        int i = 0, j=1, nxt=0;
        while (j < n)
        {
            int cur = compare(arr[j-1], arr[j]);
            if(cur==0)
                i = j;
            else if(j == n-1 || cur * compare(arr[j], arr[j+1]) != -1){
                ans = max(ans, j - i + 1);
                i = j;
            }
            j++;
        }
        return ans;
    }
};