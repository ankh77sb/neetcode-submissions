class Solution {
    vector<vector<int>> dp;
    int recur(vector<int>& nums, int target, int i, int sum, int tot, int n) {
        if(i >= n) return (sum == target) ?  1: 0;

        if(dp[i][sum + tot] != -1)
            return dp[i][sum + tot];

        int x = recur(nums, target, i + 1, sum + nums[i], tot, n);
        int y = recur(nums, target, i + 1, sum - nums[i], tot, n);
        return dp[i][sum + tot] = x + y;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        // - sum to sum
        dp.resize(n, vector<int> (2 * sum + 1, -1));

        return recur(nums, target, 0, 0, sum, n);
    }
};
