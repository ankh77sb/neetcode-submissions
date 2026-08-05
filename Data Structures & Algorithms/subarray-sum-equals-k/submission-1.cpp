class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int presum = 0;
        int res = 0;
        unordered_map<int,int> st;
        st[0] = 1;
    
        for(int n: nums) {
            presum += n;
            if(st.find(presum - k)!=st.end()) {
                res += st[presum-k];
                // cout<<"yyy"<<endl;
            }
            st[presum]++;
        }

        return res;
        
    }
};