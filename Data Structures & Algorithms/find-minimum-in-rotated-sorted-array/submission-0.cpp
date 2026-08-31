class Solution {
public:
    int findMin(vector<int> &nums) {

        int n = nums.size();
        int start = 0;
        int end = n - 1;
        int res = nums[0];

        while(start <= end) {
            if (nums[start] < nums[end]) {
                res = min(res, nums[start]);
                break;
            }
            int mid = start + (end - start)/2;
            res = min(res, nums[mid]);
            if(nums[start] > nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;   
            }
        }

        return res;
    }
};
