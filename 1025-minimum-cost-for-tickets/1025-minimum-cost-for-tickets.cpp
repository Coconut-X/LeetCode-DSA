class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
    int total_cost = 0;
    int left7 = 0, left30 = 0; // Pointers for 7-day and 30-day windows

    vector<int> dp(n, 0); // To store minimum cost for each day in days

    for (int right = 0; right < n; ++right) {
    
        while (days[right] - days[left7] >= 7) left7++;

        while (days[right] - days[left30] >= 30) left30++;

        int cost1 = (right > 0 ? dp[right - 1] : 0) + costs[0];  // 1-day pass
        int cost7 = (left7 > 0 ? dp[left7 - 1] : 0) + costs[1];  // 7-day pass
        int cost30 = (left30 > 0 ? dp[left30 - 1] : 0) + costs[2]; // 30-day pass
        
        dp[right] = min({cost1, cost7, cost30});
    }

    return dp[n - 1];
    }
};