class Solution {
public:
    #define ll long long
    vector<int> parent, rnk;

    int findSet(int a)
    {
        if(a != parent[a])
            parent[a] = findSet(parent[a]);
        return parent[a];
    }
    void unionSet(int a, int b){
        a = findSet(a);
        b = findSet(b);

        if(a != b){
            if(b < a){
                parent[a] = b;
                rnk[b] += rnk[a];
            }
            if(a < b){
                parent[b] = a;
                rnk[a] += rnk[b];
            }
        }
    }
    int longestConsecutive(vector<int> &nums){
        int n = nums.size();
        if(n==0)
            return 0;

        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rnk.assign(n, 1);

        map<ll, int> mpToParent;
        for (int i = 0; i < n; i++)
            mpToParent[nums[i]] = i;

        for (int i = 0; i < n; i++){
            if(mpToParent.find(nums[i]-1) != mpToParent.end()){
                unionSet(mpToParent[nums[i] - 1], mpToParent[nums[i]]);
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++){
            ans = max(ans, rnk[i]);
        }
        return ans;
    } 
};