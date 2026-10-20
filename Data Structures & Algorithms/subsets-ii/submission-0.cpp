class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int>& curr, int idx, vector<int>& nums) {
        if(idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        curr.push_back(nums[idx]);
        backtrack(curr, idx + 1, nums);
        curr.pop_back();

        while(idx + 1 < nums.size() && nums[idx] == nums[idx+1]) {
            idx++;
        }

        backtrack(curr, idx + 1, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(curr, 0, nums);

        return res;
    }
};
