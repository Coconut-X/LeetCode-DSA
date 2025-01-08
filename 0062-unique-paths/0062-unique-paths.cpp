class Solution {
public:

    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) ^ hash<T2>()(p.second);
        }
    };

    unordered_map<pair<int,int>,int, pair_hash> dist;

    int move(int x, int y, int m, int n)
    {
        if(x>m or y>n) return 0; //out of bounds

        if(dist[{x,y}]) return dist[{x,y}]; //if already present use memo

        if( x==m and y==n)  return 1;

        int d = move(x+1,y,m,n) + move(x,y+1,m,n);
        dist[{x,y}]=d;
        
        return d;
    }

    int uniquePaths(int m, int n) {
    
        return move(1,1,m,n); //starting from 1,1 (0,0 in grid)
    }
};