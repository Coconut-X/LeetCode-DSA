class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int h=0, s=0;
        for(int i=0;i<gain.size();i++)  h=max(h,s+=gain[i]);
        return h;
    }
};