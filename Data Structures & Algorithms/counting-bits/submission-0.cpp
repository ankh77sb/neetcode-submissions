class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res(1,0);
        if(n == 0) return res;
       // cout<<n<<endl;
        for(int i = 1; i <= n; i++) {
            // cout<<i<<endl;
            int count = 0;
            int idx = i;
            while(idx > 0) {
                // cout<<idx<<endl;
                if(idx & 1)
                    count++;
                idx >>= 1;
            }
            res.push_back(count);
        }

        return res;
    }
};
