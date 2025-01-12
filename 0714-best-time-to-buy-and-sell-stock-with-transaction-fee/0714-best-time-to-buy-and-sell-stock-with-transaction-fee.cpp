class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int totalProfit = 0;
        int buyPrice = prices[0]; 

        for (int i = 1; i < n; i++) {
  
            if (prices[i] > buyPrice + fee) {
                totalProfit += prices[i] - buyPrice - fee;
           
                buyPrice = prices[i] - fee;
            }
            
            else if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
        }

        return totalProfit;
    }
};
