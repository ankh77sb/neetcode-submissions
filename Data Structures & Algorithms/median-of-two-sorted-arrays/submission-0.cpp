class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        }

        int total = n1 + n2;
        int half = total / 2;

        int start = 0;
        int end = n1;

        while (start <= end) {

            int i = start + (end - start) / 2;
            int j = half - i;

            int aleft = (i > 0) ? nums1[i - 1] : INT_MIN;
            int aright = (i < n1) ? nums1[i] : INT_MAX;

            int bleft = (j > 0) ? nums2[j - 1] : INT_MIN;
            int bright = (j < n2) ? nums2[j] : INT_MAX;

            // Correct partition
            if (aleft <= bright && bleft <= aright) {

                // Odd number of elements
                if (total % 2) {
                    return min(aright, bright);
                }

                // Even number of elements
                return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            }

            // Too many elements taken from nums1
            if (aleft > bright) {
                end = i - 1;
            }
            // Too few elements taken from nums1
            else {
                start = i + 1;
            }
        }

        return 0.0;
    }
};