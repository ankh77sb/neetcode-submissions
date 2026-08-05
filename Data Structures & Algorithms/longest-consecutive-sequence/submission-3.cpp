class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int> mp;

        for(int n : nums) {
            mp.insert(n);
        }
    

        int maxi = 0;
        for(int i = 0; i < n ; i++) {
            if(mp.find(nums[i]-1)==mp.end()) {
                int x = nums[i];
                int cnt = 0;
                while(mp.find(x)!=mp.end()) {
                    cnt++;
                    x++;
                }
                maxi = max(maxi, cnt);
            }
        }

        return maxi;
    }
};
