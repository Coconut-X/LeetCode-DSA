// class Solution {
// public:

//     struct pair_hash{
//         template<typename T1, typename T2>
//         size_t operator()(const pair<T1, T2>& p) const{
//             auto h1=hash<T1>{}(p.first);
//             auto h2=hash<T2>{}(p.second);
//             return h1 ^ (h2<<1);
//         }

//     };

//     unordered_map<pair<int,int>, bool, pair_hash> v;

//     int trapRainWater(vector<vector<int>>& heightMap) {
//         int count=0;
//         int m=heightMap.size();
//         int n=heightMap[0].size();

//         auto isLess=[](int x, int y,vector<vector<int>> h){
//             return h[x][y]<h[x-1][y] or h[x][y]<h[x][y-1] or h[x][y]<h[x+1][y] or h[x][y]<h[x][y+1];
//         };

//         for(int i=0; i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i<m-1 and j<n-1 and i>0 and j>0)
//                 {
//                     if(isLess(i,j,heightMap))
//                     {
//                         count++;
//                         heightMap[i][j]++;
//                     }
//                 }
//             }
//         }

//         return count + 1;
        
//     }
// };

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Push all boundary cells into the heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.emplace(heightMap[i][j], make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        // Directions for neighboring cells
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            int x = cell.first, y = cell.second;

            for (const auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;

                // Check bounds and if the cell is already visited
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    // Calculate water trapped
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    // Update height to the max of current height or neighbor's height
                    minHeap.emplace(max(height, heightMap[nx][ny]), make_pair(nx, ny));
                    visited[nx][ny] = true;
                }
            }
        }

        return waterTrapped;
    }
};
