class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        
        vector<pair<int, int>> rm(n + 1, {n + 1, 0});
        vector<pair<int, int>> cm(n + 1, {n + 1, 0});

        for (auto &p : b) {
            int r = p[0]; 
            int c = p[1]; 
            
            rm[r].first = min(rm[r].first, c);
            rm[r].second = max(rm[r].second, c);

            cm[c].first = min(cm[c].first, r);
            cm[c].second = max(cm[c].second, r);
        }

        int c = 0;
        
        for (int i = 0; i < b.size(); i++) {
            int r = b[i][0]; 
            int j = b[i][1]; 
            
            pair<int, int> rr = rm[r];
            pair<int, int> cr = cm[j]; 

            bool crb = (j > rr.first && j < rr.second);
            bool ccb = (r > cr.first && r < cr.second);

            if (crb && ccb) {
                c++;
            }
        }

        return c;
    }
};