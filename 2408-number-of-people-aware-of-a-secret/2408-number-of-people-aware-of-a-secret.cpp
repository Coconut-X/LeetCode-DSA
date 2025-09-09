class Solution {
public:
    unordered_map<int,int> mep;
    const int MOD = 1000000007;

    int spread(int &totalDays, int &delay, int &forget, int daysremtoforget, int relday, int curday){
        if (curday > totalDays) return 0;

        if (mep.count(curday)) return mep[curday];

        long long ans = 0;
        // count this person if they still remember at the end of day totalDays
        if (curday + forget > totalDays) ans = 1;

        int start = curday + delay;
        int end = min(curday + forget - 1, totalDays);
        for (int t = start; t <= end; ++t) {
            // each day t in the range creates one new person who learned on day t
            ans = (ans + spread(totalDays, delay, forget, forget, 1, t)) % MOD;
        }

        return mep[curday] = (int)ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget) {
        mep.clear();
        return spread(n, delay, forget, forget, 1, 1);
    }
};
