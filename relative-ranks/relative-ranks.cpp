class Solution {
public:
    static bool comp(int a, int b){
        return a > b;
    }
    vector<string> findRelativeRanks(vector<int> &score) {
        unordered_map<int, int> idx_mp;
        int n = score.size();
        for (int i = 0; i < n; i++)
            idx_mp[score[i]] = i;

        sort(score.begin(), score.end(), comp);
        vector<string> ans(n);
        for (int i = 0; i < n; i++){
            if(i==0)
                ans[idx_mp[score[i]]] = "Gold Medal";
            else if(i==1)
                ans[idx_mp[score[i]]] = "Silver Medal";
            else if(i==2)
                ans[idx_mp[score[i]]] = "Bronze Medal";
            else
                ans[idx_mp[score[i]]] = to_string(i+1);
        }
        return ans;
    }
};