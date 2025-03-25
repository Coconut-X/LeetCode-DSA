class Solution {
public:
       bool check(vector<vector<int>>& r, int isX, int p1, int p2){
        auto xComp = [](vector<int>&a, vector<int>&b){
            if(a[0] == b[0])  return a[2] < b[2];
            return a[0] < b[0];
        };
        auto yComp = [](vector<int>&a, vector<int>&b){
            if(a[1] == b[1])  return a[3] < b[3];
            return a[1] < b[1];
        };
        sort(r.begin(), r.end(), isX?xComp:yComp);
        int count = 0;
        for(int i = 0, end = r[i][p1]+1; i < r.size(); ++i){
            if(end <= r[i][p1]) count++;
            end = max(end, r[i][p2]);
        }
        return (count >= 2);
    }
    
    bool checkValidCuts(int n, vector<vector<int>>& r) {
        return (check(r, 1, 0, 2) || check(r, 0, 1, 3));
    }
};