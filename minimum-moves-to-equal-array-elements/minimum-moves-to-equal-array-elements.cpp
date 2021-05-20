class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int diff= 0;
        for(int i=nums.size()-1; i>0; i--){
            // cout << "diff=" << diff << endl;
            nums[i] += res;
            // cout << "nums[i]=" << nums[i] << endl;
            diff = nums[i]-nums[0];
            nums[0] = nums[i];
            res += diff;
        }
        return res;
    }
};