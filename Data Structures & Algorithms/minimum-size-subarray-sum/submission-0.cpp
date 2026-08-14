class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int l = 0;
        int r = 0;
        long long int runningSum = 0;
        int res = INT_MAX;

        while(r < n) {
            runningSum += nums[r];
            r++;
            while(runningSum >= target) {
                res = min(res, r - l);
                runningSum -= nums[l];
                l++;
            }
        }

        if(res == INT_MAX)
            return 0;
        else 
            return res;
        
    }
};