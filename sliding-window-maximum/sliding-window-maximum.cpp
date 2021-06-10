class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<int> res;
        deque<int> dq;

        int i;
        for (i = 0; i < n; i++){
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(i+1 >= k){
                res.push_back(nums[dq.front()]);
            }
            
            if(i-dq.front()+1==k){
                dq.pop_front();
            }
        }

        return res;
    }
};