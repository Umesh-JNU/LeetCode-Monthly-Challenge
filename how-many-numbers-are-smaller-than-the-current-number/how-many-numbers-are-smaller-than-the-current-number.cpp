class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size(), cnt;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            cnt = 0;
            for(int j=0; j<n; j++){
                if(nums[j] < nums[i]) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
        // ----------------------------
        /*
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) mp[nums[i]]=i;
        sort(nums.begin(), nums.end());
        
        vector<int> ans(nums.size(), 0);
        ans[mp[nums[0]]]=0;
        int cnt=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i-1]) cnt++;
            ans[mp[nums[i]]]=cnt;
        }
        
        return ans;
        */
    }
};