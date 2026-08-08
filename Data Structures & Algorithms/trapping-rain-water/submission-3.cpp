class Solution {
public:
    int trap(vector<int>& a) {

        int n = a.size();
        if(n < 3) return 0;
        int res = 0;

        int l = 0;
        int r = n - 1;
        int maxLeft = 0, maxRight = 0;

        while(l < r) {
            if(a[l] <= a[r]) {
                if(a[l] > maxLeft) {
                    maxLeft = a[l];
                } else {
                    res += (maxLeft - a[l]);
                }
                l++;
            } else {
                if(a[r] > maxRight){
                    maxRight = a[r];
                } else {
                    res += (maxRight - a[r]);
                }
                r--;
            }
        }
        return res;
    }
};
