class Solution {
public:

    struct pair_hash{
        template<typename T1, typename T2>
        size_t operator()(const pair<T1,T2>& p) const{
            auto h1=hash<T1>{}(p.first);
            auto h2=hash<T2>{}(p.second);
            return h1^(h2<<1);
        }
    };

    unordered_map<pair<int,int>, int, pair_hash> dp;

    int move(vector<vector<int>>& grid, int x, int y, int m, int n)
    {
        if(x > m or y > n) return INT_MAX;
        if(x==m and y==n) return grid[x][y];
        if (dp[{x,y}]) return dp[{x,y}];
        int right= move(grid, x, y+1, m, n);
        int down = move(grid, x+1, y, m, n);
        dp[{x,y}]= grid[x][y] + min(right, down);
        return dp[{x,y}];
    }

    int minPathSum(vector<vector<int>>& grid) {
        return move(grid, 0,0, grid.size()-1, grid[0].size()-1);
    }
};