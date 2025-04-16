
class DSU{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x)
    {
        if(parent[x]!=x) //if not parent of itself
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    bool unionFind(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX!=rootY)//means different parents->different components->can merge
        {
            if(rank[rootX] > rank[rootY])
            {
                parent[rootY]=rootX;
            }
            else if (rank[rootY] > rank[rootX])
            {
                parent[rootX]=rootY;
            }
            else
            {
                parent[rootY]=rootX; //rootY is not child of X, so rank of X has increased 
                rank[rootX]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<vector<int>> adj;

        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({i,j,d });
            }
        }

        sort(adj.begin(), adj.end(), [](const vector<int>& a, const vector<int>& b) 
        {
            return a[2] < b[2];
        });

        int n = points.size();
        DSU dsu(points.size());
        int count = 0;
        int used = 0;

        for(int i = 0;i<adj.size();i++)
        {
            if(dsu.unionFind(adj[i][0],adj[i][1]))
            {
                count+=adj[i][2];
                used++;
            }
            if(used==n-1) break;
        }


        return used==n-1?count:-1;
        
        
    }
};