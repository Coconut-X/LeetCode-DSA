class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        auto sides=[](int x, int y, int m, int n, vector<vector<int>>& g)
        {
            if(g[x][y]==0) return 0;
            int a = x==0 + y==0 + x==m-1 + y==n-1;
            int b=0;

            if(x<m and x+1<m)
            {
                if(!g[x+1][y]) b++;
            }
            if(x==m-1 and m!=1)
            {
                if(!g[x-1][y])b++;
            }
            if(y<n and y+1<n)
            {
                if(!g[x][y+1])b++;
            }
            if(y==n-1 and n!=1)
            {
                if(!g[x][y-1]) b++;
            }

            return a+b;
        } ;

        int s = 0;
        for(int i =0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0) continue;
                s+=4;
                if(i-1>=0)
                {
                    if(grid[i-1][j]==1) s--,s--;
                }
                if(j-1>=0)
                {
                    if(grid[i][j-1]==1) s--,s--;
                }
            }
        }

        return s;
        
    }
};