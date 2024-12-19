class Solution {
public:
    vector<vector<bool>> visited;

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) 
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || visited[x][y] || grid[x][y] == '0')
            return;

        visited[x][y] = true;
        
        dfs(grid, visited, x + 1, y); // down
        dfs(grid, visited, x - 1, y); // up
        dfs(grid, visited, x, y + 1); // right
        dfs(grid, visited, x, y - 1); // left
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        visited.resize(rows, vector<bool>(cols, false));

        int count = 0;

        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                if (grid[i][j] == '1' && !visited[i][j]) 
                {
                    //if not visted by previous dfs, means it is new island
                    count++; 
                    dfs(grid, visited, i, j);
                }
            }
        }

        return count;
    }
};
