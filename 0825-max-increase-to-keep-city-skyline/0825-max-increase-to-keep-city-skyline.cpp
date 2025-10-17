class Solution {
public:

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int s = grid.size();
        //find maximum heights in all 4 directions
        //find min of all these 4
        //if this minh is greater than current, we can raise height by minh-current
        //we need two 1d matrices to store max for rows and cols

        //instead of taking east and west as two directions we can store their maximum as one max only for each row
        // same for north and south

        //find max in each row, this also covers max of east and west
        vector<int>maxRow(s, 0);

        for(int i = 0; i < s; i++){
            int m = grid[i][0];
            for(int j = 0; j < s; j++){
                m = max(m, grid[i][j]);
            }
            maxRow[i] = m;
        }

        //find max in each col, this also covers max of north and south
        vector<int>maxCol(s, 0);

        for(int i = 0; i < s; i++){
            int m = grid[0][i];
            for(int j = 0; j < s; j++){
                m = max(m, grid[j][i]);
            }
            maxCol[i] = m;
        }

        int sum = 0;
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                int mrow = maxRow[i], mcol = maxCol[j];
                int smallest = min(mrow, mcol); //smallest building in all four directions (not only the adjacent but upto the boundary of the city)
                if(smallest>grid[i][j]) sum+= smallest - grid[i][j];//if current building is smaller than this, we can safely elevate it till it matches height of the smallest building in neighbour 
            }
        }
        return sum;
    }
};