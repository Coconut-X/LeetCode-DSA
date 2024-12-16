class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> map;
        vector<int> nodes;
        int nodecount=0;
        for (int i = 0; i < edges.size(); i++) {
            if (map[edges[i][0]]++ == 0)
                nodecount++, nodes.push_back(edges[i][0]);
            if (map[edges[i][1]]++ == 0)
                nodecount++, nodes.push_back(edges[i][1]);
        }
        int ans = nodes[0];
        for (int i = 0; i< nodes.size(); i++)
        {
            if (map[nodes[i]] == nodecount - 1)
                ans = nodes[i];
        }
        return ans;
    }
};