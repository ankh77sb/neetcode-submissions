class KthLargest {
    priority_queue<int, vector<int>, greater<int>> q;
    int kay;
public:
    KthLargest(int k, vector<int>& nums) {
        kay = k;
        for(int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        while(q.size() > k) {
            q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > kay)
            q.pop();
        int t = q.top();
        return t;
    }
};
