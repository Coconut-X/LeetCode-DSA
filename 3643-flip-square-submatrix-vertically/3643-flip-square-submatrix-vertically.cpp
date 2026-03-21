class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        for(int j = y; j < k+y; j++){
            for(int i = x; i < k/2 +x; i++){
                swap(grid[i][j], grid[2*x+k-i-1][j]);
            }
        }
       
        return grid;
    }
};