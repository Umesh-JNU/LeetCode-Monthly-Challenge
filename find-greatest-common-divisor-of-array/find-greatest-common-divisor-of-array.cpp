class Solution {
public:
    int GCD(int a, int b){
        if(a==0)
            return b;
        return GCD(b % a, a);
    }
    int findGCD(vector<int> &nums)
    {
        int g = *max_element(nums.begin(), nums.end());
        int s = *min_element(nums.begin(), nums.end());
        return GCD(g, s);
    }
};