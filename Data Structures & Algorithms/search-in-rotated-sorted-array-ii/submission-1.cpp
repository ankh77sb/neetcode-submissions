class Solution {
public:
    bool search(vector<int>& a, int target) {

        int n = a.size();
        int start = 0;
        int end = n - 1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            // cout<<mid<<endl;
            if(a[mid] == target) return true;
            if(a[start] < a[mid]) {
                // cout<<a[start]<<" "<<a[mid]<<" "<<a[end]<<endl;
                if(a[start] <= target && target < a[mid]) {
                    // cout<<a[start]<<" "<<a[mid]<<" "<<a[end]<<endl;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if(a[start] > a[mid]) {
                if(a[mid] < target && target <= a[end]) {
                    start = mid + 1;
                } else end = mid - 1; 
            } else {
                start++;
            }
        }

        return false;
        
    }
};