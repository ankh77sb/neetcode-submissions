class Solution {
    vector<vector<int>> res;
    void dfs(int i, vector<int> currList, int total, vector<int>& candidates, int target) {
        if(total == target) {
            res.push_back(currList);
            return;
        }
        if (total > target || i == candidates.size()) {
            return;
        }
        currList.push_back(candidates[i]);
        dfs(i+1, currList, total + candidates[i], candidates, target);
        currList.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
            i++;
        dfs(i+1, currList, total, candidates, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, {}, 0, candidates, target);
        return res;
    }
};
