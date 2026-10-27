class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int startidx = 0;
        vector<int> lastidx(26, -1);
        vector<int> res;
        for(int i = 0; i < n; i++) {
            lastidx[s[i]-'a'] = i;
        }
        int last = lastidx[s[startidx] - 'a'];
        for(int i = 0 ; i < n; i++) {
            if(i == last) {
                res.push_back(i - startidx + 1);
                startidx = i + 1;
                if(startidx < n)
                    last = lastidx[s[startidx] - 'a'];
            } else {
            last = max(last, lastidx[s[i] - 'a']);
            }
        }

        return res;
    }
};
