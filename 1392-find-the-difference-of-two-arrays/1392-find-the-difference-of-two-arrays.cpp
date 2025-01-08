class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(),nums1.end());
        unordered_set<int> n2(nums2.begin(),nums2.end());   //to remove duplicate vaues
        unordered_map<int, bool> m1, m2;// for fast checking in sets
        //we can use .count also but it will take O(n2) then, thats why store in hash also
        vector<int> d1,d2;

        unordered_set<int>::iterator itr;
        
        for(itr=n1.begin();itr!=n1.end();itr++)
            m1[*itr]=true;

        for(itr=n2.begin();itr!=n2.end();itr++)
            m2[*itr]=true;
        
        for(itr=n1.begin();itr!=n1.end();itr++)
            if(!m2[*itr]) d1.push_back(*itr);

        for(itr=n2.begin();itr!=n2.end();itr++)
            if(!m1[*itr]) d2.push_back(*itr);

        return {d1,d2};

    }
};