class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0;
        for(int i=0; i<nums.size(); i++){
            switch(nums[i]){
                case 0:
                    zeros++;
                    break;
                case 1:
                    ones++;
                    break;
            }
        }
        // set 0        
        for(int i=0; i<zeros; i++) nums[i]=0;
        // set 1
        for(int i=zeros; i<zeros+ones; i++) nums[i]=1;
        // set 2
        for(int i=zeros+ones; i<nums.size(); i++) nums[i]=2;
    }
};