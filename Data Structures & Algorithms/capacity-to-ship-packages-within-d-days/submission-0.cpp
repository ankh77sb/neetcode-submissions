class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long end = 0;
        long long start = 0;
        for(int i = 0; i < n; i++) {
            end += weights[i];
            start = max(start, (long long)weights[i]);
        }
        
        long long res = end;
        while(start <= end) {
            long long mid = start + (end - start)/2;
            long long curr = mid;
            int d = 1;
            for (int i = 0; i < n; i++) {
                if (curr >= weights[i]) {
                    curr -= weights[i];
                } else {
                    curr = mid - weights[i];
                    d++;
                }
            }
            if(days >= d) {
                res = mid;
                end = mid - 1;
            } else start = mid + 1;
        }

        return (int)res;   
    }
};