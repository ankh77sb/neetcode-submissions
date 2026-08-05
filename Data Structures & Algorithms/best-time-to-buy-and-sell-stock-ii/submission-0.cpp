class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int start = -prices[0];

        for(int i = 1 ; i < n; i++) {
            if(prices[i-1] > prices[i]) {
                start += prices[i-1];
                start -= prices[i];
            }
        }

        start+=prices[n-1];

        return max(start,0);
    }
};