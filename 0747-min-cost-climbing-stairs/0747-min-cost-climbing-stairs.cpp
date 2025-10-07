struct pair_hash{
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2>& p)const{
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

class Solution {
public:
    unordered_map<int,int>mep;
    int climb(vector<int>&cost, int index){
        if(index>=cost.size()){
            return 0;
        }
       
        if (mep.count(index)) return mep[index];
       
        int one = cost[index] + climb(cost, index+1);
        int two = cost[index] + climb(cost, index+2);
        return mep[index] = min(one,two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(climb(cost,0), climb(cost,1));
    }
};