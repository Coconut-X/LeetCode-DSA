class Solution {
public:
    bool isHappy(int n) {

        unordered_map<long long, bool> present;

        long long sum=0;

        while(sum!=1)
        {
            sum=0;
            while(n>0)
            {
                long r=n%10;
                sum+=(r*r);
                n/=10;
            }

            if(sum==1 or sum==7) return true; 
            if(present[sum]) return false;
            present[sum]=true;
            n=sum;
        }

        return true;

    }
};