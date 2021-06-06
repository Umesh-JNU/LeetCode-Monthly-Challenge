class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int res=0;
        int i, j=0;
        map<int, int> freq;
        for(i=0; i<nums.size(); i++){
            freq[nums[i]]++,
            sum += nums[i];
            while(i-j+1 != freq.size()){
                freq[nums[j]]--;
                if(freq[nums[j]]==0){
                    freq.erase(nums[j]);
                }
                sum -= nums[j];
                j++;
            }
            res = max(res, sum);
        }
        return res;
    }
};