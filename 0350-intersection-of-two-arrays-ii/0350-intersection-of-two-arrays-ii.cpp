class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mep1;
        unordered_map<int, int> mep2;
        unordered_map<int, bool> mep3;



        for(int i=0;i<nums1.size();i++){
            mep1[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            mep2[nums2[i]]++;
        }

        vector<int> res;

        for(int i=0;i<nums1.size();i++){

            if(mep1[nums1[i]] and mep2[nums1[i]] and !mep3[nums1[i]]){

                int num = min(mep1[nums1[i]], mep2[nums1[i]]);

                for(int x=1;x<=num;x++){
                    res.push_back(nums1[i]);
                }
                mep3[nums1[i]]=true;

            }
        }

        return res;


        
    }
};