class Solution {
public:
    bool isHappy(int n) {

        unordered_map<long long, bool> present;

        long long sum=0;

        int t=n;
        while(sum!=1)
        {
            t=n;
            sum=0;

            while(t>0)
            {
                long r=t%10;
                sum+=(r*r);
                t/=10;
            }

            if(sum==1 or sum==7) return true; 
            if(present[sum]) return false;
            present[sum]=true;
            n=sum;

        }

        return true;

    }
};