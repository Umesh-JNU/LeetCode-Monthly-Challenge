class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0;
        for(auto e: nums) a ^= e;
        
        int bit = 1;
        while(1){
            if((bit & a) == 0)
                bit <<= 1;
            else break;
        }
        
        int b = 0, c = 0;
        for(auto e: nums) {
            if(e & bit)
                c ^= e;
            else
                b ^= e;
        }
        return {c, b};
    }
};
