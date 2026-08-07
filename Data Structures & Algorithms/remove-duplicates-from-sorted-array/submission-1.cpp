class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int res = 0;
        int next = 1;

        int n = nums.size();

        while(next < n) {
            if(nums[next] == nums[res]) {
                next++;
            } else {
                res++;
                nums[res] = nums[next++];
            }
        }

        return min(n, res + 1);
        
    }
};