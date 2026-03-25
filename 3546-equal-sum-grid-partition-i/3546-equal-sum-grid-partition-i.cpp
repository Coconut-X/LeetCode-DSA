class Solution {
public:
    vector<vector<long long>> prefix; //global  
    long long tot = 0;
    void Prefix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        tot = 0;
        prefix.resize(matrix.size(), vector<long long>(matrix[0].size(),0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tot+=matrix[i][j];
                prefix[i][j] = matrix[i][j];
                if (i > 0) prefix[i][j] += prefix[i - 1][j];
                if (j > 0) prefix[i][j] += prefix[i][j - 1];
                if (i > 0 && j > 0) prefix[i][j] -= prefix[i - 1][j - 1];
            }
        }
    }
        
    long long sumRegion(int r1, int c1, int r2, int c2) {
            long long total = prefix[r2][c2];
            long long top = (r1 > 0) ? prefix[r1 - 1][c2] : 0;
            long long left = (c1 > 0) ? prefix[r2][c1 - 1] : 0;
            long long overlap = (r1 > 0 && c1 > 0) ? prefix[r1 - 1][c1 - 1] : 0;
            long long sum = total - top - left + overlap;
            return sum;
    }



    bool canPartitionGrid(vector<vector<int>>& grid) {

        Prefix(grid);
        
        for(int i = 0; i < prefix.size(); i++){
            long long cut1 = sumRegion(0,0,i,grid[0].size() - 1);
            long long cut2 = tot - cut1;
            if(cut1 == cut2) return true;
        }

        for(int i = 0; i < prefix[0].size(); i++){
            long long cut1 = sumRegion(0,0,grid.size() - 1, i);
            long long cut2 = tot - cut1;
            if(cut1 == cut2) return true;
        }
        return false;
    }
};