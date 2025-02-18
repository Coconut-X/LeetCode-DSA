class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size()%2 == 0 && nums2.size()%2 == 0) return 0;
        int ans = 0;
        if(nums2.size() % 2 ) for(auto n: nums1) ans = ans^n;
        if(nums1.size() % 2 ) for(auto n: nums2) ans = ans^n;
        return ans;
        
    }
};