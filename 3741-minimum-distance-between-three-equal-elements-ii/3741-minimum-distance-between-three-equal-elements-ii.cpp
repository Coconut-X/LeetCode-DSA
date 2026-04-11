class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mep;
        for (int i = 0; i < nums.size(); ++i) {
            mep[nums[i]].push_back(i);
        }

        int count = INT_MAX;

        for (auto& e : mep) {
            const vector<int>& pos = e.second;
            
            if (pos.size() < 3) continue;
            for (int i = 0; i + 2 < pos.size(); ++i) {
                int dist = 2 * (pos[i + 2] - pos[i]);
                count = min(count, dist);
            }
        }

        return (count == INT_MAX) ? -1 : count;
    }
};
