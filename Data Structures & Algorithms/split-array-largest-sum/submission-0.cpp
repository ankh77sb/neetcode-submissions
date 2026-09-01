class Solution {
public:
    bool canDivide(vector<int> &nums, long long int mid, int k) {
        int divisions = 1;
        long long int curr = mid;
        for(int i = 0; i < nums.size(); i++) {
            if(curr - nums[i] >= 0) {
                curr -= nums[i];
            } else {
                divisions++;
                curr = mid - nums[i];
            }
        }

        return divisions <= k;
    }
    int splitArray(vector<int>& nums, int k) {

        long long int end = 0;
        long long int start = 0;
        long long int res = INT_MAX;
        int n = nums.size();
        for(int i= 0; i <n; i++) {
            end += nums[i];
            start = max(start,(long long) nums[i]);
        }
        res = end;
        while(start <= end) {
            long long int mid = start + (end - start)/2;
            if(canDivide(nums, mid, k)) {
                res = min(res, mid);
                end = mid - 1;
            } else { start = mid + 1; }
        }

        return res;
        
    }
};