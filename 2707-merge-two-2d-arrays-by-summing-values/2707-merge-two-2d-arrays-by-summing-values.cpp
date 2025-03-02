class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int> n1,n2;
        unordered_map<int, bool> done;
        vector<vector<int>> merge;

        for(auto n: nums1) n1[n[0]]=n[1];

        for(auto n: nums2) n2[n[0]]=n[1];

        for(int i=0;i<nums1.size();i++)
        {
            if(done[nums1[i][0]]) continue;
            merge.push_back({nums1[i][0], n1[nums1[i][0]]+n2[nums1[i][0]]});
            done[nums1[i][0]]=true;
        }

        for(int i=0;i<nums2.size();i++)
        {
            if(done[nums2[i][0]]) continue;
            merge.push_back({nums2[i][0], n1[nums2[i][0]]+n2[nums2[i][0]]});
            done[nums2[i][0]]=true;
        }

        sort(merge.begin(), merge.end(), [](const vector<int> &r1, const vector<int> &r2){ 
            return r1[0]<r2[0];
        });

        return merge;

    }
};