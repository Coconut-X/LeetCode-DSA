class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int mincost = 0;
        for(int i = 0; i < cost.size(); i++) mincost+=((i+1)%3==0?0:cost[i]);
        return mincost;
    }
};