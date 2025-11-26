class Solution {
public:
    const int mod = 1000000007; 
    int move(vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int &k, int i, int j, int &m, int &n, int rem){
        if(i < 0 or j < 0 or i >= m or j >= n) return 0;
        rem = (rem + grid[i][j])%k;
        if(i == m - 1 and j == n - 1) return rem == 0;
        if(dp[i][j][rem]!=-1) return dp[i][j][rem];
        return dp[i][j][rem] = (move(grid ,dp, k, i + 1, j, m, n, rem) + move(grid, dp, k, i, j + 1, m, n, rem)) % mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
        return move(grid, dp, k, 0, 0, m, n, 0);
    }


};