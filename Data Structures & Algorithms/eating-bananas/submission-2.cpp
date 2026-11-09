class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        long long res = high;
        while(low<=high) {
            long long mid = low + (high - low)/2;
            long long curr = 0;
            for(int i = 0; i < n; i++) {
                curr += ceil(piles[i]/(double)mid);
            }
            if(curr <= h) {
                high = mid - 1;
                res = min(res, mid);
            } else {
                low = mid + 1;
            }
        }

        return (int) res;
    }
};
