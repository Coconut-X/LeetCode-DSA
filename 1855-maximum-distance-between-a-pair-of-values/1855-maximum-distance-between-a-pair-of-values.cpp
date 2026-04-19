class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = 0;//nums1.size() - 1;
        int m = 0;
        while(l < nums1.size() and r < nums2.size()){
            if(nums1[l]<=nums2[r] and l <= r){
                m = max(m, r - l);
                r++;
            }
            else{
                l++;
            }
            if(l > r){
                r = l+1;
            }
        }
        return m;
        
    }
};