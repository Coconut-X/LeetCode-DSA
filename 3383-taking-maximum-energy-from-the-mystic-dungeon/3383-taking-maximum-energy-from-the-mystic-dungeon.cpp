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
    //vector<vector<int>>dp;
    unordered_map<pair<int,int>, int, pair_hash> dp;
    int jump(vector<int>&e, int k, int index){
        if(index>=e.size()){
            return 0;
        }
        if(dp[{index,k}]) return dp[{index,k}];
        return dp[{index,k}] = e[index]+jump(e,k,index+k);
    }

    int maximumEnergy(vector<int>& energy, int k) {

        int m = INT_MIN;
        //vector<vector<int>>dp(energy.size(),vector<int>(energy.size(),INT_MIN));
        for(int i = 0; i < energy.size(); i++){
            m = max(m, jump(energy,k,i));
        }
        return m;
        
    }
};