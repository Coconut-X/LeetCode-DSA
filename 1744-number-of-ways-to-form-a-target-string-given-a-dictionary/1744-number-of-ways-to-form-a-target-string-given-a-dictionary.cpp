
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        // Step 1: Precompute character frequencies at each column
        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        // Step 2: Dynamic programming table
        vector<vector<long>> dp(m + 1, vector<long>(n + 1, 0));
        dp[0][0] = 1;  // Base case: One way to form an empty target

        // Step 3: Fill the DP table
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Case 1: Skip the current column in words
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;

                // Case 2: Use the current column to match target[i]
                if (i < m && freq[target[i] - 'a'][j] > 0) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * freq[target[i] - 'a'][j]) % MOD;
                }
            }
        }

        // The result is stored in dp[m][n]
        return dp[m][n];
    }
};
