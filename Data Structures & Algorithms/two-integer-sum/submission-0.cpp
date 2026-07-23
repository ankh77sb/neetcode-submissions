class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        mp.insert({nums[0],0});

        int n = nums.size();

        for(int i = 1 ; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end())
                return {mp[target-nums[i]],i};
            if(mp.find(nums[i]) == mp.end())
                mp.insert({nums[i],i});
        }

        return {-1,-1};
    }

    
};
