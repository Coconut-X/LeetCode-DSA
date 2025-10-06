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
    unordered_map<pair<int,int>,int, pair_hash> mep;
    int brute(vector<int>&coins, int &amount, int index, long long current){
        if(current==amount) return 0;

        if(index==coins.size() or current>amount){
            return INT_MAX -1;
        }
        if(mep.count({index,current}))return mep[{index,current}];
        //include self again
        int b = brute(coins,amount,index+1, current);
        int a = brute(coins,amount,index, current+coins[index]);
       
        return mep[{index,current}] = min(1+a,b);
    }

    int coinChange(vector<int>& coins, int amount) {
        
        int ans = brute(coins,amount,0,0);

        if(ans>=INT_MAX-1) return -1;
        return ans;
    }
};