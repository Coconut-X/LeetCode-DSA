class Solution {
public:

    vector<vector<bool>>v;
    int bfs(int x, int y, int r, int c, vector<vector<int>>& grid) 
    {
        if (x < 0 || x >= r || y < 0 || y >= c || v[x][y] || !grid[x][y]) {
            return 0;
        }

        if (grid[x][y] == 1) 
        {
            v[x][y] = true;
            int area = 1 + bfs(x, y - 1, r, c, grid) +
                    bfs(x, y + 1, r, c, grid) +
                    bfs(x + 1, y, r, c, grid) +
                    bfs(x - 1, y, r, c, grid);
            return area;
        }

        return 0;
    }



    int maxAreaOfIsland(vector<vector<int>>& grid) {

        v.resize(grid.size(),vector<bool>(grid[0].size(),false));

        int s =0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(!v[i][j])
                {
                    s = max(s,bfs(i,j,grid.size(),grid[i].size(),grid));
                }
            }            
        }

        return s;
        
    }
};