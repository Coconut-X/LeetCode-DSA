class Solution {
public:
    int maxScore(string s) {
        
        unordered_map<int,int> zeros, ones;

        int n=s.size(), left=0, right=0, m=0;
        for(int i=0, j=n-1;i<n;i++,j--)
        {
            left+=s[i]=='0', right+=s[j]=='1';
            zeros[i]=left, ones[j]=right;
        }

        for(int k=0;k<n-1;k++)
        {
            m=max(m,zeros[k]+ones[k+1]);
        }

        return m;
    }
};