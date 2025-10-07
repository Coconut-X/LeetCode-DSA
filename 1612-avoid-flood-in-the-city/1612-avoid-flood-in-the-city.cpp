class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, queue<int>> rainDays;
        
        for (int i = 0; i < n; i++) {
            if (rains[i] > 0)
                rainDays[rains[i]].push(i);
        }

        unordered_map<int, bool> wet;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake > 0) {
                rainDays[lake].pop(); // remove today
                if (wet[lake]) return {}; // flood
                
                wet[lake] = true;
                if (!rainDays[lake].empty())
                    pq.push({rainDays[lake].front(), lake});
            } 
            else {
                if (!pq.empty()) {
                    auto [_, lakeToDry] = pq.top();
                    pq.pop();
                    wet[lakeToDry] = false;
                    ans[i] = lakeToDry;
                } else {
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
};
