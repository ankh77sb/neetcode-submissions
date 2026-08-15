class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        int l = 0, r = 0;
        vector<int> res;

        /* Priority queue solution is TC: O(NlogN)
        priority_queue<pair<int,int>> maxHeap;

        for(int i = 0 ; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        res.push_back(maxHeap.top().first);

        for(int i = k ; i < n; i++) {
            maxHeap.push({nums[i], i});
            while(maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            res.push_back(maxHeap.top().first);
        } */

        // Deque TC: O(n)
        deque<pair<int,int>> maxx;

        for(int i = 0; i < n ; i++) {
            while(maxx.size() > 0 && (maxx.front().second <= i - k)){
                maxx.pop_front();
            }
            while(maxx.size() > 0 && (maxx.back().first <= nums[i])){
                maxx.pop_back();
            }

            maxx.push_back({nums[i],i});
            if(i>=k-1) {
                res.push_back(maxx.front().first);
            }
        }

       
        return res;
    }
};
