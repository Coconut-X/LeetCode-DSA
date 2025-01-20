class Solution {
public:

    struct pair_hash{
        template<typename T1, typename T2>
        size_t operator()(const pair<T1,T2>& p)const{
        auto h1=hash<T1>{}(p.first);
        auto h2=hash<T2>{}(p.second);
        return h1^(h2<<1);
        }
    };

    bool isPathCrossing(string path) {

        int x=0, y=0;

        unordered_map<pair<int,int>, bool, pair_hash> m;
        m[{0,0}]=true;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='N')        y++;
            else if(path[i]=='S')   y--;
            else if(path[i]=='E')   x++;   
            else if(path[i]=='W')   x--;

            if(m[{x,y}]) return true;
            m[{x,y}]=true;
        }

        return false;
        
    }
};