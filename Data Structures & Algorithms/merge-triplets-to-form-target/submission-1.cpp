class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        bool a = false, b = false, c = false;
       
        for(int i = 0; i < n; i++) {           
            a |= (triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]);
            b |= (triplets[i][0] <= target[0] && triplets[i][1] == target[1] && triplets[i][2] <= target[2]);
            c |= (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] == target[2]);;      
        }
    

        return (a && b && c);

    }
};
