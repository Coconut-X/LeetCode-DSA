class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int s = prices.size();
        int i = 0;
        while(i < s){
            //using i < s will make us advance to the next index due to one extra increment of i to break for loop
            while(i+1!=s and prices[i+1]<= prices[i]){ ////skip the downfall
                i++; 
            }
            if(i>=s) return profit; //nothing bought

            //else this point is maybe end of array of turning point or a plateaue
            int buy = prices[i]; //we can also select first index with this one

            //now find the next peak
            while(i+1!=s and prices[i+1]>=prices[i]){
                i++;
            }
            if(i>=s) return profit; //dont remove current buy because we couldnt sell it so we assume we didnt buy it
            int sold = prices[i];
            profit +=sold-buy;
            i++;
        }
        return profit;
    }
};