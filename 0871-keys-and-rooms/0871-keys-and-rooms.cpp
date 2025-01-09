class Solution {
public:

    void dfs(int s, vector<bool>& v,vector<vector<int>>& rooms)
    {
        v[s]=true;

        for(int i=0;i<rooms[s].size();i++)
        {
            if(!v[rooms[s][i]])
            {
                v[rooms[s][i]]=true;
                dfs(rooms[s][i],v,rooms);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);

        dfs(0,visited,rooms);

        for(int i=0;i<visited.size();i++)
            if(!visited[i])
                return false;
        
        return true;
    }
};