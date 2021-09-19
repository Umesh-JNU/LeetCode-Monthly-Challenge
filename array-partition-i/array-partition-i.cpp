class Solution {
public:
    static bool comp(int a, int b){
        return a > b;
    }
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        int ans=0;
        for(int i=1; i<nums.size(); i+=2)
            ans += nums[i];
        
        return ans;
    }
};