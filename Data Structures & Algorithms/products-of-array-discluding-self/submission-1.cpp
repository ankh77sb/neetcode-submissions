class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prefix = 1;
        for(int i = 1 ; i < n ; i++) {
            res[i] = prefix * nums[i-1];
            prefix = res[i];
        }
        prefix = 1;
        for(int i = n - 1 ; i >= 0 ; i--) {
            res[i] = res[i] * prefix;
            prefix *= nums[i];
        }


        return res;

    }
};
