class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int n = nums.size();
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for(int i = 1; i < n; i++) {
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);

            totalSum += nums[i];
        }

        if(totalSum == minSum) return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};