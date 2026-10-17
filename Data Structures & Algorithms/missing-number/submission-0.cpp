class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(unsigned int i = 1; i <= nums.size(); i++) {
            res ^= i;
            res ^= nums[i-1];
        }
        return res;
    }
};
