class Solution {
public:
    int deleteAndEarn(vector<int> &nums)
{
    vector<int> freq(10001, 0);
    for (int i = 0; i<nums.size(); i++)
        freq[nums[i]] += nums[i];

    int inc = 0, exc = 0;
    for (int i = 0; i < 10001; i++){
        int ni = exc + freq[i];
        int ne = max(inc, exc);

        exc = ne;
        inc = ni;
    }
    return max(inc, exc);
}
};