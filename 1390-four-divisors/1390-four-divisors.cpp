class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto &n: nums){
            if(n <= 5) continue;
            int c = 1;
            int s = n;
            for(int i = 1; i <=n/2; i++){
                if(n%i == 0){
                    c++;
                    s+=i;
                }
                if(c == 5) break;
            }
            if(c == 4) sum+=s;
        }
        return sum;
    }
};