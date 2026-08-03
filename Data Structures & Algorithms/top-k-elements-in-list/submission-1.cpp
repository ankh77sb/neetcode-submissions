class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n = nums.size();
        vector<vector<int>> pq(n+1);
        unordered_map<int,int> mp;

        for(int x: nums) {
            mp[x]++;
        }

        for(pair<int,int> ele: mp){
            pq[ele.second].push_back(ele.first);
        }

        vector<int> ans;
        for(int i = n; i > 0 && k > 0; i--){
            for(int j = pq[i].size() - 1; j >=0 && k-- > 0; j-- )
                ans.push_back(pq[i][j]);
        }
        
        return ans;
    }
};
