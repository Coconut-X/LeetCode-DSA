class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int r = maze.size();
        int c = maze[0].size();
        const int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int steps = 0;
        
        while (!q.empty()) {
            int size = q.size();
            steps++; 
            
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for (const auto& dir : directions) 
                {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    
                    if (nx >= 0 && ny >= 0 && nx < r && ny < c && maze[nx][ny] == '.') 
                    {
                        if (nx == 0 || ny == 0 || nx == r - 1 || ny == c - 1) 
                            return steps;
                        
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        
        return -1;
    }
};
