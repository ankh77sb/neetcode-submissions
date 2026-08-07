class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();

        for(int i = 0, j = n - 1 ; i < n;) {
            if(numbers[i] + numbers[j] > target) {
                j--;
            } else if(numbers[i] + numbers[j] < target) {
                i++;
            } else {
                return {i+1, j+1};
            }
        }

        return {-1, -1};
        
    }
};
