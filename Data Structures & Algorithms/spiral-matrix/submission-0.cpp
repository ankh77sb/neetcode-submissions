class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};

        int n = matrix[0].size();
        vector<int> res;

        for(int i = 0; i < (min(m, n) + 1) / 2; i++) {

            // Top row
            for(int j = i; j < n - i; j++) {
                res.push_back(matrix[i][j]);
            }

            // Right column
            for(int j = i + 1; j < m - i; j++) {
                res.push_back(matrix[j][n - i - 1]);
            }

            // Bottom row (only if different from top)
            if(i < m - i - 1) {
                for(int j = n - i - 2; j >= i; j--) {
                    res.push_back(matrix[m - i - 1][j]);
                }
            }

            // Left column (only if different from right)
            if(i < n - i - 1) {
                for(int j = m - i - 2; j > i; j--) {
                    res.push_back(matrix[j][i]);
                }
            }
        }

        return res;
    }
};