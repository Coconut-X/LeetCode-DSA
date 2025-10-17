class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> all(n + 1); 
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            all[groupSizes[i]].push_back(i);
        }

        for (int i = 1; i <= n; i++) {
            int groupSize = i; 
            vector<int> temp;

            for (int j = 0; j < all[i].size(); j++) {
                temp.push_back(all[i][j]);
                if ((int)temp.size() == groupSize) {
                    ans.push_back(temp);
                    temp.clear(); 
                }
            }
        }
        return ans;
    }
};
