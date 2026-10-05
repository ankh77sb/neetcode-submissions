class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& done) {
        if(visited[i]) return false;
        if(done[i]) return true;
        visited[i] = true;
        done[i] = true;
        for(auto child: adj[i]) {
            if(!dfs(child, adj, visited, done)) {
                return false;
            }
        }
        visited[i] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<bool> visited(numCourses,false);
        vector<bool> done(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i,adj,visited, done)) return false; 
        }

        return true;
    }
};
