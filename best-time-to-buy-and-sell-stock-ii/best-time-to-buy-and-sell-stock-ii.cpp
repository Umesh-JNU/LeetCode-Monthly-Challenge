class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), buy = prices[0];
        int ans = 0;
        // increasing and decreasing
        for(int i=1; i<prices.size(); i++){
            ans = max(prices[i]-buy, ans);
            buy = min(buy, prices[i]);
        }
        
        buy = prices[0];
        int ans2 = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < prices[i-1]){
                ans2 += prices[i-1]-buy;
                buy = prices[i];
            }
        }
        if(buy != prices[n-1])
            ans2 += prices[n-1]-buy;
        return max(ans, ans2);
    }
};