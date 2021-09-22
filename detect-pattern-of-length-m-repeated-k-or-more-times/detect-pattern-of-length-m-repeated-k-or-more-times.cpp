class Solution {
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int n = arr.size(), ans = 0;
        for (int i = 0; i + m < n; i++){
            if(arr[i] != arr[i+m])
                ans = 0;
            ans += (arr[i] == arr[i + m]);
            if(ans == (k-1)*m)
                return true;
        }
        return false;
    }
};