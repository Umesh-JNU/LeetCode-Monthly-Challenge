class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size(), ans = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int low = i+1, high = n-1;
                while(low < high){
                    int sum = nums[i] + nums[low] + nums[high];
                    if(sum > target)
                        high--;
                    else if(sum < target)
                        low++;
                    else{
                        return target;
                    }
                    if(abs(target - sum) < diff){
                        ans = sum;
                        diff = abs(target - sum);
                    }
                }
            }
        }
        return ans;
    }
};