class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0, maxReach = 0; i <= maxReach && i < n; ) {
            maxReach = max(i + nums[i], maxReach);
            if(maxReach >= n - 1) return true;
            i++;
        }
        return false;
    }
};
