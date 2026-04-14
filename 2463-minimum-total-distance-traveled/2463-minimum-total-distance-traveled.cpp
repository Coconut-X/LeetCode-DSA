class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        int n = robot.size();
        int m = factory.size();

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 1e16));
        
        for (int i = 0; i <= m; i++) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= m; i++) {
            int factoryPos = factory[i-1][0];
            int factoryLimit = factory[i-1][1];
            
            for (int j = 0; j <= n; j++) {
                dp[i][j] = dp[i-1][j];
                
                long long currentDistance = 0;
                for (int k = 1; k <= factoryLimit && j - k >= 0; k++) {
                    currentDistance += abs(robot[j - k] - factoryPos);
                    
                    if (dp[i-1][j-k] != 1e16) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-k] + currentDistance);
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};