class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, s = prices.size(), i = 0;
        while(i < s){
            while(i+1!=s and prices[i+1]<= prices[i]) i++; //skip downhill
            if(i>=s) return profit; //nothing bought
            int buy = prices[i]; 
            while(i+1!=s and prices[i+1]>=prices[i]) i++; //now find the next peak
            if(i>=s) return profit; //nothing sold
            profit +=prices[i++]-buy;
        }
        return profit;
    }
};