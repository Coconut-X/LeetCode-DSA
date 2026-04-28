class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> merge;

        for(auto g:grid){
            for(int i=0;i<g.size();i++){
                merge.push_back(g[i]);
            }
        }

        sort(merge.begin(),merge.end());

        int ms = merge.size();

        int median = merge[ms/2];
        int count = 0;
        for(auto m: merge){
            if(abs(median-m)%x!=0){
                return -1;
            }
            count += abs(m - median) / x;
        }

        return count;
        
    }
};