class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        int n = arr.size();
        int l = 0;
        int r = n - 1;
        int mid = (l+r)/2;
        int ans = 0;

        while(l<=r) {
            mid = (l + r)/2;
            if(arr[mid] == x) {
                ans = mid;
                break; 
            } else if(arr[mid] < x) {
                l = mid + 1;
                ans = mid;
            } else r = mid - 1;
        }
        l = ans;
        r = ans + 1;

        cout<<ans<<endl;

        vector<int> res;
        deque<int> temp;    

        for(int count = 0; l >= 0 && r < n && k > 0; k--) {
            if(abs(x - arr[l]) <= abs(arr[r] - x)) {
                temp.push_front(arr[l]);
                cout<<arr[l]<<endl;
                l--;
            } else {
                temp.push_back(arr[r]);
                cout<<arr[r];
                r++;
            }
        }

        for(int count = 0; l >= 0 && k > 0; k--) {
                temp.push_front(arr[l]);
                l--;
        }

        for(int count = 0; k > 0 && r < n; k--) {
            temp.push_back(arr[r]);
            r++;
        }

        res.assign(temp.begin(), temp.end());
        return res;
        
    }
};