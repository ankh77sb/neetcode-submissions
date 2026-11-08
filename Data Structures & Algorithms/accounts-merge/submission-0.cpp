class Solution {
public:
    int findParent(vector<int>& parent, int x) {
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent, parent[x]);
    }

    void unite(vector<int>& parent, int x, int y) {
        int parentX = findParent(parent, x);
        int parentY = findParent(parent, y);

        if(parentX == parentY) return;

        if(parentX < parentY) {
            parent[parentY] = parentX;
        }
        else {
            parent[parentX] = parentY;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();

        vector<int> parent(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Step 1: Union accounts sharing an email
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                }
                else {
                    unite(parent, mp[accounts[i][j]], i);
                }
            }
        }

        // Step 2: Group emails by ultimate parent
        vector<set<string>> res(n);

        for(int i = 0; i < n; i++) {
            int root = findParent(parent, i);

            for(int j = 1; j < accounts[i].size(); j++) {
                res[root].insert(accounts[i][j]);
            }
        }

        // Step 3: Construct final result
        vector<vector<string>> final;

        for(int i = 0; i < n; i++) {
            if(res[i].empty()) continue;

            vector<string> merged;
            merged.push_back(accounts[i][0]);

            for(auto& email : res[i]) {
                merged.push_back(email);
            }

            final.push_back(merged);
        }

        return final;
    }
};