/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int n = mountainArr.length();

        if(n<=2) return -1;

        int start = 1, end = n - 2;
        int mid = -1;

        while(start<=end) {
            mid = start + (end - start)/2;
            int y = mountainArr.get(mid);
            int x = mountainArr.get(mid - 1);
            int z = mountainArr.get(mid + 1);

            if(x < y && y > z) {
                break;
            } else if(x < y && y < z) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // search left half
        start = 0;
        end = mid;

        while(start <= end) {
            int mid2 = start + (end - start)/2;
            int y = mountainArr.get(mid2);
            if(y == target) return mid2;
            else if(y < target) {
                start = mid2 + 1;
            } else end = mid2 - 1;   
        }

        // search right half
        start = mid;
        end = n - 1;

        while(start <= end) {
            int mid2 = start + (end - start)/2;
            int y = mountainArr.get(mid2);
            if(y == target) return mid2;
            else if(y < target) {
                end = mid2 - 1;
            } else start = mid2 + 1;   
        }

        return -1;
        
    }
};