class Solution {
public:
    int trap(vector<int>& h) {
        int s = h.size();
        int lmax = h[0], rmax = h[s-1];
        int low =1, high = s-1;

        int ans = 0;
        while(low<=high)
        {
            if(lmax<rmax)
            {
                ans+= max(0,lmax - h[low]);
                lmax = max(lmax,h[low]);
                low++;
            }
            else
            {
                ans+=max(0, rmax-h[high]);
                rmax = max(rmax,h[high]);
                high--;
            }
        }
        return ans;
    }
};