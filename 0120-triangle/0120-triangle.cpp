struct pairHash {
    template <class T1, class T2>
    size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ (h2 << 1);
    }
};
class Solution {
public:
    int dfs(vector<vector<int>>& tri, int row, int index, unordered_map<pair<int,int>,int,pairHash>&mep){
        if(row==tri.size()) return 0;
        if(index == tri[row].size()) return 0;
        if(mep.count({row,index})) {
            return mep[{row,index}];
        }

        mep[{row,index}] = tri[row][index] + min(dfs(tri,row+1,index,mep), dfs(tri,row+1,index+1,mep));
        return mep[{row,index}];
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        unordered_map<pair<int,int>, int, pairHash>mep;
        return dfs(triangle,0,0,mep);
        
    }
};