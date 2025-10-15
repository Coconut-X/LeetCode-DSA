class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        for(int i = 0; i < g.size(); i++){
            auto it = lower_bound(s.begin(), s.end(),g[i]);
            if(it==s.end()) continue;
            int d = distance(s.begin(), it);
            count++;
            s[d] = -1;
        }
        return count;
    }
};