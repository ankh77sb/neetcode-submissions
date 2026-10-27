class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool> incl(n, true);
        for(int j = 0 ; j < 3; j++) {
            for(int i = 0; i < n; i++) {
                if(target[j] < triplets[i][j])
                   incl[i] = false; 
            }
        }
        int a = 0, b = 0, c = 0;
        for(int j = 0; j < 3; j++) {
            for(int i = 0; i < n; i++) {
                if(incl[i]) {
                    a = max(a, triplets[i][0]);
                    b = max(b, triplets[i][1]);
                    c = max(c, triplets[i][2]);
                }
            }
        }

        return (a == target[0] && b == target[1] && c == target[2]);

    }
};
