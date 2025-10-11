class Solution {
public:
    long long dfs(vector<int>& set, unordered_map<int,long long>& count, unordered_map<int,long long>& dp, int i) {
        if (i >= set.size()) return 0;
        if (dp.count(set[i])) return dp[set[i]];

        int cur = set[i];
        int j = i + 1;
        while (j < set.size() && set[j] <= cur + 2) j++;

        long long take = count[cur] * 1LL * cur + dfs(set, count, dp, j);
        long long skip = dfs(set, count, dp, i + 1);

        return dp[cur] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long> count, dp;
        for (int x : power) count[x]++;

        vector<int> set;
        for (auto &p : count) set.push_back(p.first);
        sort(set.begin(), set.end());

        return dfs(set, count, dp, 0);
    }
};
