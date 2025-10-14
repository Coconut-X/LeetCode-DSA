int binarySearch(vector<tuple<int,int,int>>& jobs, int index, int target) {
    int low = index + 1, high = (int)jobs.size() - 1;
    int ans = jobs.size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (get<0>(jobs[mid]) >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

class Solution {
public:
    unordered_map<int, int> dp;

    int brute(vector<tuple<int,int,int>>& jobs, int index) {
        if (index >= (int)jobs.size()) return 0;
        if (dp.count(index)) return dp[index];

        int cs = get<0>(jobs[index]);
        int ce = get<1>(jobs[index]);
        int profit = get<2>(jobs[index]);

        int next = binarySearch(jobs, index, ce);

        int take = profit;
        if (next < (int)jobs.size())
            take += brute(jobs, next);

        int skip = brute(jobs, index + 1);

        return dp[index] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<tuple<int,int,int>> jobs;

        for (int i = 0; i < n; i++)
            jobs.push_back({startTime[i], endTime[i], profit[i]});

        sort(jobs.begin(), jobs.end()); 

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, brute(jobs, i));

        return ans;
    }
};
