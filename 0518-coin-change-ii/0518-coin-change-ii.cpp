struct pair_hash{
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>&p) const{
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:

    //unordered_map<pair<int,int>,long long, pair_hash> mep;
    vector<vector<int>>dp;
    int brute(vector<int>&coins, int &amount, int index, int current, vector<vector<int>>&dp){
        if(current==amount) return 1;

        if(index==coins.size() or current>amount){
            return 0;
        }
        if(dp[index][current]!=-1)return dp[index][current];
        //include self again
        int b = brute(coins,amount,index+1, current, dp);
        int a = brute(coins,amount,index, current+coins[index], dp);
       
        return dp[index][current] = a+b;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return brute(coins, amount,0,0,dp);
    }
};