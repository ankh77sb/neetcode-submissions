class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& curr,
                   int i, vector<int>& nums, vector<bool>& vis) {

        if(vis[i]) return;

        curr.push_back(nums[i]);
        vis[i] = true;

        if(curr.size() == nums.size()) {
            res.push_back(curr);
        }
        else {
            for(int j = 0; j < nums.size(); j++) {
                backtrack(res, curr, j, nums, vis);
            }
        }

        curr.pop_back();
        vis[i] = false;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(), false);
        vector<vector<int>> res;
        vector<int> curr;

        for(int i = 0; i < nums.size(); i++) {
            backtrack(res, curr, i, nums, vis);
        }

        return res;
    }
};