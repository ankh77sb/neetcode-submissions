class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> res;
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int ele: nums) {
            mp[ele]++;
        }

        for(auto& entry: mp) {
            if(entry.second > n/3) {
                res.push_back(entry.first);
            }
        }

        return res;
        
    }
};