class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        vector<int> post(n, 1);
        vector<int> pre(n, 1);

        for(int i = 1 ; i < n - 1 ; i++) {
            pre[i] = pre[i-1] * nums[i-1];
            post[n - i - 1] = post[n - i] * nums[n - i]; 
        }

        pre[n-1] = pre[n-2] * nums[n-2];
        post[0] = post[1] * nums[1];

        for(int i = 0 ; i < n; i++) {
            res[i] = post[i] * pre[i];
        }

        return res;

    }
};
