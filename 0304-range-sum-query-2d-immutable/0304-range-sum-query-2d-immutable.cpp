class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        prefix.resize(matrix.size(), vector<int>(matrix[0].size(),0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                prefix[i][j] = matrix[i][j];
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        int total = prefix[r2][c2];
        int top = (r1 > 0) ? prefix[r1 - 1][c2] : 0;
        int left = (c1 > 0) ? prefix[r2][c1 - 1] : 0;
        int overlap = (r1 > 0 && c1 > 0) ? prefix[r1 - 1][c1 - 1] : 0;
        int sum = total - top - left + overlap;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */