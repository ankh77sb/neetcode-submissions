class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        queue<pair<int,int>> q;
        priority_queue<int> pq;

        int res = 0;
        vector<int> count(26,0);
        for(char c: tasks) {
            count[c-'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count[i])
                pq.push(count[i]);
        }

        while(!pq.empty() || !q.empty()) {
            res++;

            if(pq.empty()) {
                res = q.front().second;
            } else {
                int cnt = pq.top() - 1;
                pq.pop();
                if(cnt > 0) q.push({cnt, res + n});
            }

            if (!q.empty() && q.front().second == res) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return res;
    }
};
