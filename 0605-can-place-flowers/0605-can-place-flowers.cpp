class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int s=f.size();
        if(s==1 and n==1) return !f[0];
        for(int i=0;i<s and n!=0;i++)
        {
            if(f[i])
            {
                 continue;
            }
            if(i>0 and i<s-1 and !f[i-1] and !f[i+1])
            {
                f[i]=1;
                n--;
                continue;
            }

            if(i==0 and i+1<s and !f[i+1])
            {
                f[i]=1;
                n--;
                continue;
            }

            if(i==s-1 and i-1>0 and !f[i-1])
            {
                f[i]=1;
                n--;
                continue;
            }
        }
        
        return !n;
    }
};