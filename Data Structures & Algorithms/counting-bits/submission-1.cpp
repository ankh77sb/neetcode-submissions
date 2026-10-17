class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res(n+1,0);
        if(n == 0) return res;

        for(int i = 1; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }
};
