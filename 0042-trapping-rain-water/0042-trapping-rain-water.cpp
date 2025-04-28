class Solution {
public:
    int trap(vector<int>& h) {
        int s = h.size();
        // vector<int> leftMax(s);
        // vector<int>rightMax(s);
        // int lmax = h[0], rmax = h[s-1];
        // for(int i=0;i<s;i++)
        // {
        //     lmax = max(lmax,h[i]);
        //     rmax = max(rmax,h[s-i-1]);
        //     leftMax[i] = lmax;
        //     rightMax[s-i-1] = rmax;
        // }

        int ans = 0;

        int lmax = h[0], rmax = h[s-1];
        int low = 1, high = s-2;
        while(low<=high)
        {
            if(lmax<rmax)
            {
                ans+= max(0,lmax - h[low]);
                lmax = max (lmax,h[low]);
                low++;
            }
            else
            {
                ans+= max(0,rmax-h[high]);
                rmax = max(rmax,h[high]);
                high--;
            }
        }
        return ans;

        return 0;
    }
};