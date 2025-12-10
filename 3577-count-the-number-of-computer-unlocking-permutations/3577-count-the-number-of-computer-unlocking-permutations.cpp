class Solution {
public:
    int countPermutations(vector<int>& c) {
        int m = c[0];

        for(int i = 1; i < c.size(); i++){
            if(c[i]<=m )return 0;
        }
        long long fact = 1;
        for(int i = 2; i <= c.size() - 1; i++){
            fact = (fact*i)%1000000007;
        }
        return (int)fact;
    }
};