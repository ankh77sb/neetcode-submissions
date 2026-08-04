class NumMatrix {
private:
    vector<vector<long long int>> presum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        presum.resize(matrix.size(), std::vector<long long int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size() ; i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                if(j==0) presum[i][j] = matrix[i][j];
                else
                presum[i][j] = presum[i][j-1] + matrix[i][j];
            }
        }

        for(int i = 0; i < matrix[0].size() ; i++) {
            for(int j = 1; j < matrix.size(); j++) {
                presum[j][i] += presum[j-1][i];
            }
        }    
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;

        if(row1>0 && col1>0) {
            ans = presum[row2][col2] - presum[row1-1][col2] - presum[row2][col1-1]
                + presum[row1-1][col1-1];
        }
        else if(row1>0) {
            ans = presum[row2][col2] - presum[row1-1][col2];
        } else if(col1>0) {
            ans = presum[row2][col2] - presum[row2][col1-1];
        } else ans = presum[row2][col2];

        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */