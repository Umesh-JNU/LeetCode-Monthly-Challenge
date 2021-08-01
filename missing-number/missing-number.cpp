class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = 0, s2 = (n*(n+1))/2;
        for (int i = 0; i < nums.size(); i++){
            s1 += nums[i];
        }
        // cout << n<<" "<<s1<<" "<<s2 << endl;
        return s2 - s1;
    }
};