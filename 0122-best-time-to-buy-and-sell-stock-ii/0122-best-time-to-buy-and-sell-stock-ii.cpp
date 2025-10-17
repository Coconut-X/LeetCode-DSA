class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        //1 2 3 4
        int s = prices.size();
        int i = 0;
        while(i < s){
            int curr = prices[i];
            cout<<"Current: "<<curr<<endl;
            
            //using i < s will make us advance to the next index due to one extra increment of i to break for loop
            while(i+1!=s and prices[i+1]<= prices[i]){ ////skip the downfall
                i++; 
            }
            if(i>=s) return profit; //nothing bought

            //else this point is maybe end of array of turning point or a plateaue
            int buy = prices[i]; //we can also select first index with this one
            //cout<<"Buying at: "<<buy<<endl;
            
            //now find the next peak
            while(i+1!=s and prices[i+1]>=prices[i]){
                i++;
            }
            if(i>=s) return profit; //dont remove current buy because we couldnt sell it so we assume we didnt buy it
            int sold = prices[i];
            //cout<<"Selling at: "<<sold<<endl;
            profit +=sold-buy;
            //cout<<profit<<endl;
            i++;
        }
        return profit;
    }
};