class Solution {
public:
    int maxScore(string s) {
        
        unordered_map<int,int> zeros;
        unordered_map<int,int> ones;

        int n=s.size();

        int left=0;
        int right=0;
        int m=0;
        for(int i=0, j=n-1;i<n;i++,j--)
        {
            if(s[i]=='0') left++;
            if(s[j]=='1') right++;
            zeros[i]=left;
            ones[j]=right;
        }

        for(int k=0;k<n-1;k++)
        {
            m=max(m,zeros[k]+ones[k+1]);
        }

        return m;

    }
};