class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int,int>mep;
        mep[0] = cost[0], mep[1] = cost[1];
        for(int i = 2; i < cost.size(); i++){
            mep[i] = cost[i] + min(mep[i-1], mep[i-2]);
        }
        return min(mep[cost.size()-1], mep[cost.size()-2]);
    }
};