class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> mp;

        for(int n : nums) {
            int curr = 1;
            if(mp.find(n-1)!=mp.end()) {
                curr = curr + mp[n-1];
            }
            if(mp.find(n)!=mp.end()) {
                mp[n] = max(mp[n],curr);
            } else mp[n] = curr;
        }

        int maxi = 0;
        for(auto& m: mp) {
            if(m.second > maxi) maxi = m.second;
        }
        

        return maxi;
    }
};
