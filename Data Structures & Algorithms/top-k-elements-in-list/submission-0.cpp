class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int, int>> pq;
        unordered_map<int,int> mp;

        int n = nums.size();

        for(int x: nums) {
            mp[x]++;
        }

        for(pair<int,int> ele: mp){
            pq.push({ele.second, ele.first});
        }

        vector<int> ans;
        while(k--) {
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
