class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0, r = 0;

        priority_queue<pair<int,int>> maxHeap;

        for(int i = 0 ; i < k; i++) {
            maxHeap.push({nums[i], i});
        }

        vector<int> res;
        res.push_back(maxHeap.top().first);

        for(int i = k ; i < n; i++) {
            maxHeap.push({nums[i], i});
            while(maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            res.push_back(maxHeap.top().first);
        }

        return res;
    }
};
