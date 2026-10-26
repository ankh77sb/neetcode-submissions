class Solution {
    vector<string> res;
    void backtrack(string s, int n, int l, int r) {
        if(s.size() == 2*n) {
            res.push_back(s);
            return;
        }

        if(l<n) {
            s.push_back('(');
            backtrack(s, n, l + 1, r);
            s.pop_back();
        }

        if(r < n && r < l){
            s.push_back(')');
            backtrack(s, n, l, r + 1);
            s.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        string s = "";
        int l = 0;
        int r = 0;
        
        backtrack(s, n, l, r);

        return res;
    }
};
