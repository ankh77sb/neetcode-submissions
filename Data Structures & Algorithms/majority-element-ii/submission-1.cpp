class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

    // Boyer-Moore Voting Algorithm
    int num1 = -1000000001;
    int num2 = -1000000001;

    int n = nums.size();
    int cnt1 = 0, cnt2 = 0;

    for(int i = 0; i < n; i++) {
        if(num1 == nums[i]) {
            cnt1++;
        }else if(num2 == nums[i]) {
            cnt2++;
        } else  if(cnt1 == 0){
            num1 = nums[i];
            cnt1++;
        }else if(cnt2 == 0){
            num2 = nums[i];
            cnt2++;
        }else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for(int num: nums) {
        if(num == num1) cnt1++;
        else if(num == num2) cnt2++;
    }

    vector<int> res;
        if (cnt1 > n / 3) res.push_back(num1);
        if (cnt2 > n / 3) res.push_back(num2);

        return res;
    }
};