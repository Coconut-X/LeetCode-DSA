class Solution {
public:

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int s = 0;
        vector<int>ans;
        for(int i = 0; i < spells.size(); i++){
            long long search = ceil((long double)success/spells[i]);
            auto it = lower_bound(potions.begin(), potions.end(),search);
            if(it==potions.end()){
                ans.push_back(0);
                continue;
            }
            int d = distance(potions.begin(),it);
            ans.push_back(potions.size()-d);
        }
        return ans;

    }
};