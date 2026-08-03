class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        for(int i = 0 ; i <= end; ){
            if(nums[i] == 0) {
                    swap(nums[i], nums[start++]);
                    i++;
            }
            else if(nums[i] == 2)
                swap(nums[i], nums[end--]);
            else i++;
        }

        return;
    }
};