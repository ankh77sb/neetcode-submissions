class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        
        vector<int> ans;
        while(!q.empty()) {
            int front = q.front();
            q.pop();

            ans.push_back(front);
            for(auto child: adj[front]) {
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }

        return ((ans.size() == numCourses)? ans: vector<int>());
    }
};
