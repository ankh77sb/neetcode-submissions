class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int size = nums.size();
        int i = 0, j = size - 1;
        for(; i < size, i <= j; ) {
            if(nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            } else if(nums[i] == val) {
                j--;
            } else {
                i++;
            }
        }

        return i;
        
    }
};