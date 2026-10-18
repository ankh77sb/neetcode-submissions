class Solution {
    priority_queue<int> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        for(int i = 0 ; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        while(pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if(x == y) {
                continue;
            } else {
                int abst = abs(x - y);
                pq.push(abst);
            }
        } 

        return (pq.empty()? 0: pq.top());
    }
};
