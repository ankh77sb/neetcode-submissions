class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        int count = 0;
        for(int i = 0; i < n; i++) {
            indegree[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int front = q.front();
            q.pop();
            count++;
            for(int child: adj[front]) {
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }

        return count == numCourses;
    }
};
