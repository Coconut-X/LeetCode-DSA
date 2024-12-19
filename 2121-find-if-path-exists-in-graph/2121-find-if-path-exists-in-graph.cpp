class Solution {
public:
    vector<bool>visited;

    bool bfs(vector<vector<int>> edges, int s, int d)
    {
        visited[s]=true;

        queue<int>q;
        q.push(s);
       
       while(!q.empty())
       {
        int node=q.front();
        q.pop();
        if(node==d) return true;

        for(int i=0;i<edges[node].size();i++)
        {
            if(!visited[edges[node][i]])
            {
                visited[edges[node][i]]=true;
                q.push(edges[node][i]);
            }
        }

       }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

    visited.resize(n,false);

      vector<vector<int>> adj(n);
        for (const auto& edge : edges)  //converting to adj list
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

    return bfs(adj,source,destination);
        
    }
};