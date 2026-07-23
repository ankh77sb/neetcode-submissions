class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        /* This is TC: O(Nlog(N)) and SC: O(1)/O(N) based on type of Sorting
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) return true;
        }

        return false;
        */

        // TC: O(N) and SC: O(N)
        return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
        
    }
};