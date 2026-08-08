class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int currmax = 0;
        int res = 0;

        for(int i = n - 1; i >= 0; i--) {
            res = max(res, currmax - prices[i]);
            currmax = max(currmax, prices[i]);
        }

        return res;

    }
};
