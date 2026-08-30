class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long int end = 0;
        int n = piles.size();

        for(int i = 0 ; i < n ; i++) {
            end += piles[i];
        }

        long long start = 1;
        long long res = 0;
        while(start <= end) {
            long long mid = start + (end - start)/2;
            long long hours = 0;
            for(int i = 0; i < n ; i++) {
                hours += ceil((double)piles[i]/mid);
            }
            if(hours<=h) {
                res = mid;
                end = mid - 1;
            } else start = mid + 1;
        }

        return (int)res;
        
    }
};
