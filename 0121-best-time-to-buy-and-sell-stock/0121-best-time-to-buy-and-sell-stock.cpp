class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = prices.size();
        //arr: 7    1    5    3    6   4
        //min: 7    1    1    1    1   1
        int profit = 0;
        int minPriceSeen = prices[0];
        for(int i = 1; i < s; i++){

            minPriceSeen = min(minPriceSeen, prices[i]);
            if(prices[i] > minPriceSeen) profit = max(profit,prices[i] - minPriceSeen);
        }
        return profit;
    }
};