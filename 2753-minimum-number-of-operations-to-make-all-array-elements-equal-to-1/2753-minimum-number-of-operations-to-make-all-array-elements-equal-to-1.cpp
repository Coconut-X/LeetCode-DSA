class Solution {
public:

    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }

    int minOperations(vector<int>& nums) {
        int count = 0;
        int m = 52;
        for(auto &n:nums) if(n==1) count++;
        if(count) return nums.size()-count;

        int overall_gcd = nums[0];
        for (int i = 1; i < nums.size(); i++) 
            overall_gcd = gcd(max(overall_gcd, nums[i]), min(overall_gcd, nums[i]));


        if(overall_gcd > 1) return -1;
        count = 0;

        for(int i = 0; i < nums.size(); i++){
            int curgcd = nums[i];
            for(int j = i; j < nums.size(); j++){
                curgcd = gcd(max(curgcd,nums[j]),min(curgcd, nums[j]));
                if(curgcd == 1){
                    m = min(m, j-i);
                    break;
                }
            }
        }
        if(m == 52) return -1;
        return nums.size()+m -1;
    }
};