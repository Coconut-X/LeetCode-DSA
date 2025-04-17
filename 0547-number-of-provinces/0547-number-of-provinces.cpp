class Solution {
public:

    void bfs(vector<vector<int>> &c, int source, vector<bool>& visited, int &count)
    {
       if(visited[source]) return;
       count++;
       queue<int>q;
       q.push(source);
       visited[source] = true;

       while(!q.empty())
       {
            int t = q.front();
            q.pop();

            for(int i =0;i<c[source].size();i++)
            {
                if(c[t][i] and !visited[i])
                {
                    q.push(i);
                    visited[i]=true;
                }
            }
       }

    }




    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<bool> v(isConnected.size(),false);
        int count = 0;

        for(int i=0;i<isConnected.size();i++)
        {
            bfs(isConnected, i,v,count);
        }

        return count;
    
        
    }
};