class Solution {
    vector<vector<int>> res;
    void subset(vector<int> &nums, int idx, vector<int>& p) {
        if(idx == nums.size()) {
            res.push_back(p);
            return;
        }
        subset(nums, idx + 1, p);
        p.push_back(nums[idx]);
        subset(nums, idx + 1, p);
        p.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        res.clear();
        
        vector<int> p;
        subset(nums, 0, p);
        return res;
    }
};
