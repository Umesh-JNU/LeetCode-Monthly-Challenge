class Solution {
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> mp;
        for(int i=0; i<list1.size(); i++)
            mp[list1[i]] = i;

        vector<string> ans;
        int min_idx = INT_MAX;
        for (int i = 0; i < list2.size(); i++){
            if(mp.find(list2[i]) != mp.end()){
                int sum = i + mp[list2[i]];
                if(sum < min_idx){
                    ans.clear();
                    ans.push_back(list2[i]);
                    min_idx = sum;
                }
                else if(sum == min_idx)
                    ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};