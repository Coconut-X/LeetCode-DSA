class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();
        int m1=0;
        int j=n-1;
        for(int i=0;i<j;)
        {
                m1=max(m1, min(h[i],h[j])*abs(i-j));
                if(h[i]<h[j]) i++;
                else j--;
        }

        return m1;
    }
};