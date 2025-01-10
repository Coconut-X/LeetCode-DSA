class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<vector<int>> transpose(n, vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                transpose[j][i]=grid[i][j];
            }
        }

        int count=0;

       for (int i = 0; i < n; i++) 
       { // rows of grid
            for (int j = 0; j < n; j++) 
            { //columns of transpose
                bool found = true;
                for (int k = 0; k < n; k++) 
                { // compare the row and column
                    if (grid[i][k] != transpose[j][k]) {
                        found = false;
                        break;
                    }
                }
                count += found;
            }
        }

        return count;
        
    }
};