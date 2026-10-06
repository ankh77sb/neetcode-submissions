class Solution {
    vector<int> v;
public:
    Solution() {
        v = vector<int> (46,0);
        v[0] = 1;
        v[1] = 1;
    }
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(v[n]) return v[n];
        v[n] = climbStairs(n - 1) + climbStairs(n-2);
        return v[n];
    }
};
