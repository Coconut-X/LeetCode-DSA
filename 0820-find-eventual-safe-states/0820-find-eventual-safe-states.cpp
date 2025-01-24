class Solution {
public:

    vector<int> v;
    vector<int> ans;

    bool dfs(int curr, vector<vector<int>>& graph)
    {
        if(v[curr]==1) return false;
        if(v[curr]==2) return true; 

        v[curr]=1;

        for(int i=0;i<graph[curr].size();i++)
            if(!dfs(graph[curr][i],graph))
                return false;

        v[curr]=2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        v.resize(graph.size(),0);

        for(int i=0;i<graph.size();i++)
            if(dfs(i,graph))
                ans.push_back(i);

        return ans;
    }
};