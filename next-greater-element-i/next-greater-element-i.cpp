class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n2; i++)
            mp[nums2[i]] = i;

        stack<int> stk;
        for (int i = n2-1; i >= 0; i--){
            while (!stk.empty() && stk.top() < nums2[i])
                stk.pop();

            if(stk.empty()){
                stk.push(nums2[i]);
                nums2[i] = -1;
            }
            else{
                int t = nums2[i];
                nums2[i] = stk.top();
                stk.push(t);
            }
        }

        for (int i = 0; i < n1; i++){
            nums1[i] = nums2[mp[nums1[i]]];
        }
        return nums1;
    }
};