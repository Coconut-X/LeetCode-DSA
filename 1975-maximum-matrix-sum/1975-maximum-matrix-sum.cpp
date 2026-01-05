class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        long long sum = 0;
        int m = INT_MAX;
        int count = 0;
        for(auto &v: matrix){
            for( auto &n : v){
                sum+=abs(n);
                count+=(n < 0);
                m = min (m, abs(n));
            }
        }
        if(count%2) sum = sum - m - m;
        return sum;
    }
};